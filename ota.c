#include<stdio.h>
#include <unistd.h>
#include<signal.h>
#include<sys/types.h>
#include <stdlib.h>

void main(void)
{
	static const char nextVerFile[] = "./nextVersion";
	static const char currVerFile[] = "./version";
	char verStr[10];
	float currVerFloat, nextVerFloat;
	FILE *file;

	/* Check for new version and update nextVersion file*/
	system("./nextversion.sh");

	/* Open and read currentVersion file and locally store current version value */

	file = fopen(currVerFile, "r");
	fscanf(file, "%f", &currVerFloat);
	printf("verFloat = %f\n", currVerFloat);
	fclose(file);

	
	/* Open and read nextVersion file and locally store next version value */
	file = fopen(nextVerFile, "r");
	fscanf(file, "%s", verStr);
	sscanf(verStr, "%f", &nextVerFloat);
	printf("verFloat = %f\n", nextVerFloat);
	fclose(file);


	if (nextVerFloat > currVerFloat)
		printf("New update %s is available\n", verStr);
	
}
 

