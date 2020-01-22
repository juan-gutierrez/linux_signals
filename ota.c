#include<stdio.h>
#include <unistd.h>
#include<signal.h>
#include<sys/types.h>
#include <stdlib.h>

void main(void)
{
	static const char filename[] = "./nextVersion";
	char verStr[10];
	float verFloat;
	FILE *file;

	/* Check for new version and update nextVersion file*/
	system("./nextversion.sh");
	
	file = fopen(filename, "r");
	fgets (verStr , 10 , file);
	sscanf(verStr, "%f", &verFloat);
	printf("verFloat = %f\n", verFloat);

}
 

