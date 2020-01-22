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
	exit(0);
}

void main(void)
{
	int i;
	signal(SIGINT,sig_handler_int);
	signal(SIGQUIT,sig_handler_quit);

	while(1) {
		printf("Which song you want to play\n");
		printf("\n");
		printf("Song1 ............. 1 \n");
		printf("Song2 ............. 2 \n");
		printf("Song3 ............. 3 \n");
		scanf("%d", &i);
	        switch (i) {
			case 1:
				system("aplay -V stereo beautiful_life-ace_of_base.wav");
				break;
			case 2:
				system("aplay -V stereo dont_speak-no_doubt.wav");
				break;
			case 3:
				system("aplay -V stereo i_ran_so_far_away-flock_of_seagulls.wav");
				break;
			default:
				printf("No valid option\n");
				break;
		}	
	}
}
 

