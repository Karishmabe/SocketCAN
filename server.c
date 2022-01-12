#include<sys/ioctl.h>
#include<linux/can.h>
#include<linux/can/raw.h>
int main()
{
int s;
int nbytes;
struct sockaddr_can addr;
struct can_frame frame;
struct ifreq ifr;
const char *ifname ="vcan0";
if((s=socket(PF_CAN,SOCK_RAW,CAN_RAW))==-1){
perror("error while opening socket ");
return -1;

}
strcpy(ifr.ifr_name,ifname);
ioctl(s,SIOCGIFINDEX,&ifr);
memset(&addr,0,sizeof(addr));
addr.can_family=AF_CAN;
addr.can_ifindex=ifr.ifr_ifindex;
printf("%s at index %d\n",ifname,ifr.ifr_ifindex);
if(bind(s,(struct sockaddr*)&addr,sizeof(addr))==-1){
perror("error in socket bind");
return -2;
}
