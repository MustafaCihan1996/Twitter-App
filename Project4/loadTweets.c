#include "headerA3.h"

void loadTweetsFromFile(tweet ** tweetList){
	tweet *addTweet;
	char line[BUFFERSIZE];
	char fileName[MAXFILENAMESIZE];
	FILE * fp;
	printf("Enter a filename to load from ");
	fgets(fileName, BUFFERSIZE, stdin);
	fileName[ strlen(fileName) - 1 ] = '\0';
	fp = fopen (fileName,"r");
	if (fp == NULL)
	{
		fprintf(stderr, "ERROR: Could not open file \'%s\'.\n", fileName);
		return;
	}
    while(fgets(line, BUFFERSIZE, fp) != NULL){
    	char text[BUFFERSIZE];
    	addTweet = malloc(sizeof(tweet));
    	addTweet->next = NULL;
    	strcpy(text,line);
    	char *token = strtok(text,", ");
    	addTweet->id = atoi(token);
    	token = strtok (NULL,", ");
    	strcpy(addTweet->user,token);
    	token = strtok (NULL,"\n");
    	strcpy(addTweet->text,token);
    	addNodeToList(tweetList,addTweet);
    	addTweet = addTweet->next;
	}
		
	fclose(fp);
	printf("Tweets imported!");
	return;
}
