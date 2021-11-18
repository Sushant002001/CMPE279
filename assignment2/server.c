// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";
    char *flag = "true";
    char arr[5];

    if (strcmp(argv[2], flag) == 0)
    {
        pwd = getpwnam("nobody");
        printf("Nobody UID: %ld\n", (long)pwd->p_uid);
        printf("Original UID is %d\n", getuid());

        if (setuid(pwd->p_uid) == -1)
        {
            perror("setuid(nobody)");
            exit(EXIT_FAILURE);
        }

        //printf("UID after setuid is %ld\n", (long)getuid());
        //printf("In child server_fd: %s\n", argv[1]);

        char const *c = argv[1];
        int numChar = atoi(c);

        if ((new_socket = accept(numChar, (struct sockaddr *)&address,
                                 (socklen_t *)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        valread = read(new_socket, buffer, 1024);
        printf("Read %d bytes: %s\n", valread, buffer);
        send(new_socket, hello, strlen(hello), 0);
        printf("Hello, Message Sent \n");
        return 0;
    }
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    printf("Initial server_fd %d\n", server_fd)
    pid_t p_id = fork();

    if (p_id == 0)
    {
        printf("Current process ID child: %d\n", getpid());
        sprintf(arr, "%d", server_fd);
        char *params[] = {argv[0], arr, flag, NULL};
        execv(argv[0], params);
        perror("execution failed");
        exit(EXIT_FAILURE);
    }
    else if(p_id < 0)
    {
        perror("Unsuccessful Fork");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
	&opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    if (bind(server_fd, (struct sockaddr *)&address,
	sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if (waitpid(p_id, &child_status, 0) <0)
    {
        perror("Could not wait");
        exit (EXIT_FAILURE);
    }

    return 0;
}
