#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 80

int main(int argc, char *argv[])
{
     int servsockfd;
     char hostname[256];
     struct hostent *hostinfo;
     struct in_addr **addr_list;
     char ip[200];
     int i;

     printf("Enter a hostname: ");
     scanf("%s",hostname);

    if ( (hostinfo = gethostbyname(hostname) ) == NULL)
    {
        perror("gethostbyname");
        return 1;
    }

    addr_list = (struct in_addr **) hostinfo->h_addr_list;

    for(i = 0; addr_list[i] != NULL; i++)
    {
        strcpy(ip , inet_ntoa(*addr_list[i]) );
    }

    printf("\nHostname: %s, resolves to IP address: %s\n",hostname,ip);
}


