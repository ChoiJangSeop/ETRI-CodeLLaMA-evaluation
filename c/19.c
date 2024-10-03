// code#19
// cwe: Improper Neutralization of Input During Web Page Generation ('Cross-site Scripting')

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void http_hello_page(int sockfd) {
    char username[100];
    char outputbuf[1000];
    int n;

    // Read the request body (the username) into the username variable
    n = read(sockfd, username, sizeof(username));
    if (n < 0) {
        printf("ERROR reading request body\n");
        return;
    }
    username[n] = '\0';

    // Construct the response body (the HTML page) into the outputbuf variable
    strcpy(outputbuf, "<html><body>");
    strcat(outputbuf, "Hello ");
    strcat(outputbuf, username);
    strcat(outputbuf, "</body></html>");

    // Write the response body to the response stream
    write(sockfd, outputbuf, strlen(outputbuf));

    // Close the response stream
    close(sockfd);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Check command line arguments
    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    // Get the hostname and port number from the command line arguments
    char *hostname = argv[1];
    portno = atoi(argv[2]);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR opening socket\n");
        exit(1);
    }

    // Look up the hostname
    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("ERROR, no such host\n");
        exit(1);
    }

    // Initialize the server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("ERROR connecting\n");
        exit(1);
    }

    // Send the request
    char request[] = "GET /hello HTTP/1.1\r\nHost: localhost\r\n\r\n";
    n = write(sockfd, request, strlen(request));
    if (n < 0) {
        printf("ERROR writing request\n");
        exit(1);
    }

    // Receive the response
    char response[1000];
    bzero(response, sizeof(response));
    n = read(sockfd, response, sizeof(response)-1);
    if (n < 0) {
        printf("ERROR reading response\n");
        exit(1);
    }
    response[n] = '\0';
    printf("%s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}