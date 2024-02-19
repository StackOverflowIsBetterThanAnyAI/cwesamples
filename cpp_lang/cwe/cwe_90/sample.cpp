#include <iostream>
#include <cstring>
#include <ldap.h>

void searchLDAP(const std::string& userInput) {
    LDAP* ld;
    int rc;

    // Se connecter au serveur LDAP (à des fins de démonstration, configurez-le selon vos besoins)
    const char* ldap_uri = "ldap://localhost:389";
    const char* ldap_bind_dn = "cn=admin,dc=example,dc=com";
    const char* ldap_bind_pw = "admin_password";

    rc = ldap_initialize(&ld, ldap_uri);
    if (rc != LDAP_SUCCESS) {
        std::cerr << "Erreur lors de l'initialisation LDAP: " << ldap_err2string(rc) << std::endl;
        exit(EXIT_FAILURE);
    }

    rc = ldap_simple_bind_s(ld, ldap_bind_dn, ldap_bind_pw);
    if (rc != LDAP_SUCCESS) {
        std::cerr << "Erreur lors de la connexion LDAP: " << ldap_err2string(rc) << std::endl;
        ldap_unbind_ext_s(ld, NULL, NULL);
        exit(EXIT_FAILURE);
    }

    // Construire la requête LDAP en concaténant l'entrée utilisateur sans validation
    std::string ldap_filter = "(uid=" + userInput + ")";

    // Effectuer la recherche LDAP avec la requête non neutralisée
    rc = ldap_search_s(ld, "ou=people,dc=example,dc=com", LDAP_SCOPE_SUBTREE, ldap_filter.c_str(), NULL, 0, NULL, NULL);
    if (rc != LDAP_SUCCESS) {
        std::cerr << "Erreur lors de la recherche LDAP: " << ldap_err2string(rc) << std::endl;
    }

    // Fermer la connexion LDAP
    ldap_unbind_ext_s(ld, NULL, NULL);
}

int main() {
    std::string userInput;

    std::cout << "Entrez un nom d'utilisateur pour la recherche LDAP : ";
    std::getline(std::cin, userInput);

    // Appel de la fonction de recherche LDAP avec l'entrée utilisateur non neutralisée
    searchLDAP(userInput);

    return 0;
}
