#include "headerA3.h"

void saveTweetsToFile(tweet * tweetList){
	char fileName[MAXFILENAMESIZE];
	FILE * fp;
	printf("Enter the filename where you would like to store your tweets: ");
	fgets(fileName, BUFFERSIZE, stdin);
	fileName[ strlen(fileName) - 1 ] = '\0';
	fp = fopen (fileName,"w");
	if (fp == NULL)
	{
		fprintf(stderr, "ERROR: Could not open file \'%s\'.\n", fileName);
		return;
	}
	while(tweetList){
		fprintf (fp, "%d, %s, %s\n",tweetList->id,tweetList->user,tweetList->text);
		tweetList = tweetList->next;
	}
	 fclose (fp);
	 printf("Output successful!\n");
	 return;
}  
