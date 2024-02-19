#include <stdio.h>
#include <stdlib.h>

void unsafe(const char *filename) {
    printf("Chargement de l'image depuis le fichier : %s\n", filename);
}

int isValidImagePath(const char *path) {
    if (strncmp(path, "/images/", 8) == 0) {
        return 1;
    }
    return 0;
}

void safe(const char *filename) {
    if (!isValidImagePath(filename)) {
        printf("Erreur : Chemin d'accès non autorisé.\n");
        return;
    }
    printf("Chargement de l'image depuis le fichier : %s\n", filename);
}

int main() {
    char userInput[50];

    printf("Entrez le nom du fichier image à charger : ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = '\0';

    unsafe(userInput);
    safe(userInput);

    return 0;
}