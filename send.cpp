#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#include <fstream>
#include <string>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>

printf("start...\n");

string sip;
string sport;
ifstream ifsip("ip.txt");
ifstream ifsport("port.txt");
ifsip >> sip;
ifsport >> sport;

printf("UDP IP : %s\n", sip.c_str());
printf("UDP IP : %d\n", stoi(sport));

int sock;
struct sockaddr_in addr;
sock = socket(AF_INET, SOCK_DGRAM, 0);
addr.sin_family = AF_INET;
addr.sin_port = htons(stoi(sport));
addr.sin_addr.s_addr = inet_addr(sip.c_str());
int val = 1;
ioctl(sock, FIONBIO, &val);
int yes = 1;
setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char *)&yes, sizeof(yes));

while(1){
    sendto(sock, "halle", sizeof("halle"), 0, (struct sockaddr *)&addr, sizeof(addr));
}