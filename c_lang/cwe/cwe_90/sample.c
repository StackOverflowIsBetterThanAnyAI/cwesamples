#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ldap.h>

void searchLDAP(const char *userInput) {
    LDAP *ld;
    int rc;

    // Se connecter au serveur LDAP (à des fins de démonstration, configurez-le selon vos besoins)
    const char *ldap_uri = "ldap://localhost:389";
    const char *ldap_bind_dn = "cn=admin,dc=example,dc=com";
    const char *ldap_bind_pw = "admin_password";

    rc = ldap_initialize(&ld, ldap_uri);
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "Erreur lors de l'initialisation LDAP: %s\n", ldap_err2string(rc));
        exit(EXIT_FAILURE);
    }

    rc = ldap_simple_bind_s(ld, ldap_bind_dn, ldap_bind_pw);
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "Erreur lors de la connexion LDAP: %s\n", ldap_err2string(rc));
        ldap_unbind_ext_s(ld, NULL, NULL);
        exit(EXIT_FAILURE);
    }

    // Construire la requête LDAP en concaténant l'entrée utilisateur sans validation
    char ldap_filter[256];
    snprintf(ldap_filter, sizeof(ldap_filter), "(uid=%s)", userInput);

    // Effectuer la recherche LDAP avec la requête non neutralisée
    rc = ldap_search_s(ld, "ou=people,dc=example,dc=com", LDAP_SCOPE_SUBTREE, ldap_filter, NULL, 0, NULL, NULL);
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "Erreur lors de la recherche LDAP: %s\n", ldap_err2string(rc));
    }

    // Fermer la connexion LDAP
    ldap_unbind_ext_s(ld, NULL, NULL);
}

int main() {
    char userInput[50];

    printf("Entrez un nom d'utilisateur pour la recherche LDAP : ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = '\0';  // Supprime le saut de ligne de fgets

    // Appel de la fonction de recherche LDAP avec l'entrée utilisateur non neutralisée
    searchLDAP(userInput);

    return 0;
}