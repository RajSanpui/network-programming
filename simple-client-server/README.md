1.
The socket API - socket(AF_INET, SOCK_STREAM, 0);

AF_INET = IPv4, 
SOCK_STREAM = stream socket or TCP, for UDP it is SOCK_DGRAM
Last argument is 0 means single protocol to be used in protocol family

2. 
struct sockaddr_in
Socket = IP address + port number, and this is what this structure is all about.
In addition it just specifies which address family - IPv4 or IPv6.

struct sockaddr_in {
    sa_family_t    sin_family; /* address family: AF_INET */
    in_port_t      sin_port;   /* port in network byte order */
    struct in_addr sin_addr;   /* internet address */
 };

 /* Internet address. */
 struct in_addr {
      uint32_t       s_addr;     /* address in network byte order */
  };






References:
https://stackoverflow.com/questions/26974179/calling-accept-gives-errorno-14-bad-address
https://www.lixu.ca/2014/09/c-implicit-declaration-of-function.html
http://man7.org/linux/man-pages/man2/accept.2.html