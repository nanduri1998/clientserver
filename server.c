#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    int sockfd, newsockfd, portno, clilen;
    char buffer[256], filename[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    FILE *fp;

    if(argc < 2){
        fprintf(stderr, "Error: No Port Provided, Please provide a port\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        error("Error opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        error("ERROR on Binding to port");
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if(newsockfd < 0){
        error("Error on accept");
    }

    bzero(buffer, 256);

    n = read(newsockfd, buffer, 255);

    if(n<0){
        error("Error in read");
    }
    strcpy(filename, buffer);
    
    bzero(buffer, 256);

    n = read(newsockfd, buffer, 255);

    if(n<0){
        error("Error in read");
    }

    printf("File Read: %s\n", filename);
    puts(buffer);
    fp = fopen(filename, "w");
    fprintf(fp, "%s", buffer);
    fclose(fp);

    n = write(newsockfd, "I got your file", 18);

    if(n < 0){
        error("Error in write");
    }

    return 0;
}