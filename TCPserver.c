#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<winsock2.h>
int main(){
    WORD wVersionRequested;
    WSADATA wsaData;
    int wsaerr;
wVersionRequested = MAKEWORD(2,2);
wsaerr = WSAStartup(wVersionRequested, &wsaData);
if(wsaerr !=0 ){
    printf("The Winsock Dll not found \n");
    return 0;
}
else{
    printf("Found\n");
    printf("The status: %s.\n",wsaData.szSystemStatus);

}
if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2 )

{

    /* Tell the user that we could not find a usable */

    /* WinSock DLL.*/

    printf("The dll do not support the Winsock version %u.%u!\n", LOBYTE(wsaData.wVersion),HIBYTE(wsaData.wVersion));

    WSACleanup();

    return 0;

}

else

{

    printf("The dll supports the Winsock version %u.%u!\n", LOBYTE(wsaData.wVersion),HIBYTE(wsaData.wVersion));

    printf("The highest version this dll can support: %u.%u\n", LOBYTE(wsaData.wHighVersion), HIBYTE(wsaData.wHighVersion));

}
SOCKET m_socket;
m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

if (m_socket == INVALID_SOCKET)
{
printf("Error at socket(): %ld\n", WSAGetLastError());

    WSACleanup();

    return 0;
}
else
{
printf("socket() is OK!\n");
}
struct sockaddr_in service;
service.sin_family = AF_INET;
service.sin_addr.s_addr = inet_addr("127.0.0.1");
service.sin_port = htons(55555);
if (bind(m_socket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR)

{

    printf("bind() failed: %ld.\n", WSAGetLastError());

    closesocket(m_socket);

    return 0;

}
else

{

   printf("bind() is OK!\n");

}
if (listen(m_socket, 1) == SOCKET_ERROR)

       printf("Server: listen(): Error listening on socket %ld.\n", WSAGetLastError());

else

{

    printf("Server: listen() is OK, I'm waiting for connections...\n");

}
SOCKET AcceptSocket;
printf("Server: Waiting for a client to connect...\n");
printf("***Hint: Server is ready...run your client program...***\n");
while (1)

{

    AcceptSocket = SOCKET_ERROR;

 

      while (AcceptSocket == SOCKET_ERROR)

       {

        AcceptSocket = accept(m_socket, NULL, NULL);

       }
    printf("Server: Client Connected!\n");

    m_socket = AcceptSocket;

    break;

}
// Till here the the socket is established, binded and the connection from the client is accepted
// Now the data and sending and recieving has to be done which is done below. .
int bytesSent;

int bytesRecv = SOCKET_ERROR;

char sendbuf[200] = "The data has been recieved thank you!!";

// initialize to empty data...

char recvbuf[200] = "";

 

 

// Receives some test string from client...and client

// must send something lol...
FILE* fptr;
	char str1;
	if ((fptr = fopen("datawrite.txt", "w")) == NULL) {
		printf("Error! opening file");

		// Program exits if the file pointer returns NULL.
		exit(1);
	}
    while(strcmp(recvbuf,"end")<0){
     char recvbuf[200] = "";
      bytesRecv = recv(m_socket, recvbuf, 200, 0); 
      
      if(strcmp(recvbuf,"end")==0){
          break;
      }
      else{
          fprintf(fptr,recvbuf);
      }
      
    //   printf("%d",bytesRecv);
    
      
    }
    
    
 

if (bytesRecv == SOCKET_ERROR)

       printf("Server: recv() error %ld.\n", WSAGetLastError());

else

{

       printf("Server: recv() is OK.\n");

       printf("Server: Received data is: \"%s\"\n", recvbuf);

       printf("Server: Bytes received: %ld.\n", bytesRecv);

}

// Send some test string to client...

// printf("Server: Sending some test data to client...\n");

bytesSent = send(m_socket, sendbuf, strlen(sendbuf), 0);

 

if (bytesSent == SOCKET_ERROR)

       printf("Server: send() error %ld.\n", WSAGetLastError());

else

{

       printf("Server: send() is OK.\n");

       printf("Server: Bytes Sent: %ld.\n", bytesSent);

}

 

WSACleanup();

return 0;

}






 