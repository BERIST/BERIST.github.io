#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/netlink.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <signal.h>    
//#include <bits/stdc++.h>
//using namespace std;
FILE *fp;
void handler(int sig)
{
	fclose(fp);
//	printf("hey");
	exit(0);
}
int quit_flag = 0;

struct read_bbr {
    unsigned int    bbr_min_rtt_us;
    unsigned int    bbr_rtt_cnt;
    unsigned int    bbr_min_rtt_stamp;
    unsigned int    bbr_full_bw;
    unsigned int    bbr_lt_bw;
    unsigned int    bbr_lt_last_delivered;
    unsigned int    rcv_nxt;
    unsigned int 	snd_wl1;
    unsigned int    snd_nxt;
    unsigned int    bbr_mode;
    unsigned int 	copied_seq;
	unsigned int  prior_inflight;
	unsigned int  est_inflight;
    unsigned short int sport;
    unsigned long  long bbr_bw;
	int gain;
//	struct timespec stime;
	unsigned long long hash;
};

#define NETLINK_TEST 31

#define NLMSG_SETECHO 0x11
#define NLMSG_GETECHO 0x12

#define MAX_PAYLOAD 101
#define MAX_MSGSIZE 1024
 
struct sockaddr_nl saddr, daddr;
struct iovec iov;
int sd;
struct nlmsghdr *nlhdr = NULL;
struct msghdr msg;
struct read_bbr *bbr_info;
int main( int argc, char **argv)
{
	signal(SIGINT,handler);
	int ret = 1;
	int len =0;
	sd = socket(PF_NETLINK, SOCK_RAW,NETLINK_TEST);  
	if(sd < 0){
		perror("error fd\n");
		return -1;
	}
        memset(&saddr, 0, sizeof(saddr));  
        memset(&daddr, 0, sizeof(daddr));  
  
        saddr.nl_family = AF_NETLINK;        
        saddr.nl_pid = 100;  
        saddr.nl_groups = 0;  
        bind(sd, (struct sockaddr*)&saddr, sizeof(saddr));  
  
	memset(&daddr, 0, sizeof(daddr));
	    daddr.nl_family = AF_NETLINK;
	    daddr.nl_pid = 0; // to kernel 
  	  daddr.nl_groups = 0;

        nlhdr = (struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_MSGSIZE));  
  
//  		freopen("b.txt","w",stdout);
	
    	fp = fopen("b.txt","w");
    	struct timeval tv; 
        while (1) {  
			memset(nlhdr,0,sizeof(struct nlmsghdr));
	                nlhdr->nlmsg_len = NLMSG_SPACE(MAX_MSGSIZE);  
	  		nlhdr->nlmsg_pid = saddr.nl_pid;
			nlhdr->nlmsg_flags = 0;
	    		nlhdr->nlmsg_type = 0;
	    		nlhdr->nlmsg_seq = 0;
			
			  /* Fill in the netlink message payload */
	        	iov.iov_base = (void *)nlhdr;
	        	iov.iov_len = nlhdr->nlmsg_len;
			//iov.iov_len = NLMSG_SPACE(MAX_PAYLOAD);
			memset(&msg, 0, sizeof(msg));
	        	msg.msg_name = (void *)&daddr;
	       		 msg.msg_namelen = sizeof(daddr);
	       		 msg.msg_iov = &iov;
	        	msg.msg_iovlen = 1;
	
			ret = recvmsg(sd,&msg,0);
	//		ret = recvfrom(sd, &bbr_info-> sizeof(struct read_bbr), 0,NULL,NULL);
	    		if(!ret)
	    		{
	        		perror("recv form kernel error\n");
	        		//close(skfd);
	        		//exit(-1);
				continue;
	   		 }
			bbr_info = (struct read_bbr*)NLMSG_DATA(nlhdr);
			gettimeofday(&tv, NULL);
			//printf("%hu\t%u\t%llu\n",bbr_info->sport, bbr_info->bbr_mode,bbr_info->bbr_bw);
//		    fprintf(fp,"%hu\t%u\t%llu\t%d\t%d\t%d\t%u\t%u\t%u\t%d\t%d\n",bbr_info->sport, bbr_info->bbr_mode,bbr_info->bbr_bw,tv.tv_sec,tv.tv_usec,bbr_info->gain,bbr_info->est_inflight,bbr_info->prior_inflight,bbr_info->bbr_min_rtt_us,bbr_info->stime.tv_sec,bbr_info->stime.tv_nsec);
		    fprintf(fp,"%hu\t%u\t%llu\t%d\t%d\t%d\t%u\t%u\t%u\t%llu\n",bbr_info->sport, bbr_info->bbr_mode,bbr_info->bbr_bw,tv.tv_sec,tv.tv_usec,bbr_info->gain,bbr_info->est_inflight,bbr_info->prior_inflight,bbr_info->bbr_min_rtt_us,bbr_info->hash);


//			printf("message len =%d recv_len=%d bbr_len=%d\n",len,ret,sizeof(struct read_bbr));
//			printf("min_rtt_us:%u rtt_cnt:%u min_rtt_stamp:%u full_bw:%u lt_bw:%u lt_last_delivered:%u bw:%llu rcv_next:%u snd_wl1:%u snd_nxt:%u copied_seq=%u sport=%hu\n", \
//	            bbr_info->bbr_min_rtt_us, bbr_info->bbr_rtt_cnt,  \
//	            bbr_info->bbr_min_rtt_stamp, bbr_info->bbr_full_bw, bbr_info->bbr_lt_bw, \
//	            bbr_info->bbr_lt_last_delivered, bbr_info->bbr_bw, (bbr_info->rcv_nxt),bbr_info->snd_wl1,(bbr_info->snd_nxt),(bbr_info->copied_seq),bbr_info->sport);
        }  
 	free(nlhdr);  
        close(sd);  
}  
 
