#include<stdio.h>
#include <unistd.h>
#include<signal.h>
#include<sys/types.h>
#include <stdlib.h>

void main(void)
{
	static const char nextVerFile[] = "./nextVersion";
	static const char currVerFile[] = "./nextVersion";
	char verStr[10];
	float currVerFloat, nextVerFloat;
	FILE *file;

	/* Check for new version and update nextVersion file*/
	system("./nextversion.sh");
	
	/* Open and read nextVersion file and locally store next version value */
	file = fopen(nextVerFile, "r");
	fgets (verStr , 10 , file);
	sscanf(verStr, "%f", &nextVerFloat);
	printf("verFloat = %f\n", nextVerFloat);
	fclose(file);

	file = fopen(currVerFile, "r");
	fgets (verStr , 10 , file);
	sscanf(verStr, "%f", &currVerFloat);
	printf("verFloat = %f\n", currVerFloat);
	fclose(file);

	if (nextVerFloat > currVerFloat)
		printf("OTA pdate is available");
	
}
 

