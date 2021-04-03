#include "headerA3.h"

tweet * createTweet( tweet * tweetList){
	char line[MAXUSERNAMESIZE];
	char lineTwo[MAXTWEETSIZE];
	tweet * newTweet;
	newTweet = malloc(sizeof(tweet));
	if (newTweet == NULL)
	{
		fprintf(stderr, "ERROR: Not enough space to create a new tweet.\n");
		return NULL;
	}
	newTweet->next = NULL;
	printf("Enter a username: ");
	fgets(line, BUFFERSIZE, stdin);
	line[ strlen(line) - 1 ] = '\0'; 
	strcpy(newTweet->user,line);
		if (strlen(newTweet->user) == 0)
	{
		fprintf(stderr, "ERROR: Username cannot be empty.\n");
		return NULL;
	}
	if(strlen(newTweet->user) > MAXUSERNAMESIZE){
	
	fprintf(stderr, "ERROR: Username cannot be more than %d characters.\n", MAXUSERNAMESIZE);	
		return NULL;
	}
	
	printf("Enter the user's tweet: ");
	fgets(lineTwo, BUFFERSIZE, stdin);
	lineTwo[strlen(lineTwo) - 1 ] = '\0';
	strcpy(newTweet->text,lineTwo);
	if (strlen(newTweet->text) == 0)
	{
		fprintf(stderr, "ERROR: Tweet text cannot be empty.\n");
		return NULL;
	}
		if(strlen(newTweet->text) > MAXTWEETSIZE){
	
	fprintf(stderr, "ERROR: Tweet Text cannot be more than %d characters.\n", MAXTWEETSIZE);	
		return NULL;
	}

	
	char *p = newTweet->user;
	int count = 0;
	while ( *p != '\0' ) {
    
	 count+=(int)*p;
  

    p++; 
      }
    newTweet->id = count;
	printf("Your computer-generated userid is %ld\n",newTweet->id+strlen(newTweet->text));

return newTweet;
}
