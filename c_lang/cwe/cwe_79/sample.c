#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

void generate_page(const char *user_input, char *output, size_t output_size) {
    // La génération de la page ne prend pas en compte l'échappement des caractères spéciaux, créant une vulnérabilité XSS
    snprintf(output, output_size,
             "HTTP/1.1 200 OK\r\n"
             "Content-Type: text/html\r\n"
             "\r\n"
             "<html><head><title>Page vulnérable</title></head><body>"
             "<p>Entrée utilisateur : %s</p>"
             "</body></html>",
             user_input);
}

int main() {
    // Code du serveur web simple (pour les besoins de la démonstration)
    const int PORT = 8080;

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Erreur lors de la création du socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Erreur lors de la liaison du socket");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, 10) == -1) {
        perror("Erreur lors de l'écoute sur le socket");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Serveur en cours d'écoute sur le port %d...\n", PORT);

    while (1) {
        int client_sock = accept(server_sock, NULL, NULL);
        if (client_sock == -1) {
            perror("Erreur lors de l'acceptation de la connexion");
            continue;
        }

        char request[1024];
        ssize_t bytes_received = recv(client_sock, request, sizeof(request) - 1, 0);
        if (bytes_received == -1) {
            perror("Erreur lors de la réception de la requête");
            close(client_sock);
            continue;
        }

        request[bytes_received] = '\0';

        // Analyse de la requête (ignorée dans cet exemple)

        // Simulation de la vulnérabilité en n'échappant pas l'entrée utilisateur
        char user_input[100];
        sscanf(request, "GET /?input=%99s", user_input);

        char response[1024];
        generate_page(user_input, response, sizeof(response));

        send(client_sock, response, strlen(response), 0);

        close(client_sock);
    }

    close(server_sock);

    return 0;
}
