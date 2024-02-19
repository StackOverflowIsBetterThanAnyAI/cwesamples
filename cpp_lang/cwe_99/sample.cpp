#include <iostream>
#include <cstring>

#define MAX_PATH_LENGTH 256

bool isValidImagePath(const std::string& path) {
    return (path.compare(0, 8, "/images/") == 0);
}

void unsafe(const std::string& filename) {
    std::cout << "Erreur : Chemin d'accès non autorisé." << std::endl;
    return;
}

void safe(const std::string& filename) {
    if (!isValidImagePath(filename)) {
        std::cout << "Erreur : Chemin d'accès non autorisé." << std::endl;
        return;
    }

    std::cout << "Chargement de l'image depuis le fichier : " << filename << std::endl;
}

int main() {
    char userInput[MAX_PATH_LENGTH];

    std::cout << "Entrez le chemin du fichier image à charger : ";
    std::cin.getline(userInput, sizeof(userInput));

    safe(userInput);

    return 0;
}
