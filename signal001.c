#include<stdio.h>
#include <unistd.h>
#include<signal.h>
#include<sys/types.h>
#include <stdlib.h>

/* Call by Ctrl + c */
void sig_handler_int(int num)
{
	printf("On SIGINT handler sig(%d)\n",num);
        system("./playBeep.sh");
}

/* Call by Ctrl + \ */
void sig_handler_quit(int num)
{
	printf("On SIGQUIT handler sig(%d)\n",num);
}

void main(void)
{
	signal(SIGINT,sig_handler_int);
	signal(SIGQUIT,sig_handler_quit);

	while(1) {
		printf("Hello\n");
		sleep(2);
	}
}
 

