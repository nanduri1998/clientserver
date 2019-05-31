#include <stdio.h>

#include <winsock2.h>

 

int main()

{

    // Initialize Winsock.

    WSADATA wsaData;

    int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

    if (iResult != NO_ERROR)

              printf("Client: Error at WSAStartup().\n");

    else

              printf("Client: WSAStartup() is OK.\n");

 

    // Create a socket.

    SOCKET m_socket;

    m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

 

    if (m_socket == INVALID_SOCKET)

    {

        printf("Client: socket() - Error at socket(): %ld\n", WSAGetLastError());

        WSACleanup();

        return 0;

    }

   else

       printf("Client: socket() is OK.\n");

 

    // Connect to a server.

   struct sockaddr_in clientService;

 

    clientService.sin_family = AF_INET;

    // Just test using the localhost, you can try other IP address

    clientService.sin_addr.s_addr = inet_addr("127.0.0.1");

    clientService.sin_port = htons(55555);

 

    if (connect(m_socket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR)

    {

        printf("Client: connect() - Failed to connect.\n");

        WSACleanup();

        return 0;

    }

    else

    {

       printf("Client: connect() is OK.\n");

       printf("Client: Can start sending and receiving data...\n");

    }
// Till here all the connection formalities are done, now sending and receiving the data is to be done as below. 
 

    // Send and receive data.

    int bytesSent;

    int bytesRecv = SOCKET_ERROR;

    // Be careful with the array bound, provide some checking mechanism...

   char sendbuf[200] = ""; 

    char recvbuf[200] = "";
    // Reading the data from a textfile and puttin it in sendbuf and a sending a continous stream of data. 
    FILE* fptr;
	char str1;
	if ((fptr = fopen("data.txt", "r")) == NULL) {
		printf("Error! opening file");

		// Program exits if the file pointer returns NULL.
		exit(1);
	}
	 
	while(fgets(sendbuf,200,fptr)){
        printf("%s",sendbuf);
		bytesSent = send(m_socket,sendbuf, strlen(sendbuf), 0);
        

       if(bytesSent == SOCKET_ERROR){

              printf("Client: send() error %ld.\n", WSAGetLastError());
       }
	

	}
    int bytesSent2 = send(m_socket,"end",4, 0);
    printf("All data sent\n");
	
    while(bytesRecv == SOCKET_ERROR)

       {

           bytesRecv = recv(m_socket, recvbuf, 200, 0);

        if (bytesRecv == 0 || bytesRecv == WSAECONNRESET)

        {

             printf("Client: Connection Closed.\n");

            break;

        }

 

        if (bytesRecv < 0)

            return 0;

       else

       {

              printf("Client: recv() is OK.\n");

              printf("Client: Received data is: \"%s\"\n", recvbuf);

              printf("Client: Bytes received is: %ld.\n", bytesRecv);

       }

    }

    
    fclose(fptr);
    WSACleanup();

    return 0;

}