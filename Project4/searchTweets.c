#include <strings.h>
#include "headerA3.h"

int searchTweetsByKeyword(tweet * tweetList){
 tweet *copy;
 int count = 0;
 copy = tweetList;
 char keyWord[MAXTWEETSIZE];
 printf("Enter a keyword to search:");
 fgets(keyWord, BUFFERSIZE, stdin);
 keyWord[ strlen(keyWord) - 1 ] = '\0';
 while(copy != NULL){
 	if(strlen(keyWord) == 1){
 	char *s = copy->text;
 	while(*s){
 		if(strchr(keyWord, *s)){	
 		printf("Match found for \'%s\': %s wrote: \"%s\"\n",keyWord,copy->user,copy->text);
		 break;	
		 }
		 s++;
		 }
		
	 }
	else{
	char text[MAXTWEETSIZE];
	strcpy(text,copy->text);
 	char *token = strtok(text, " .,?!");
 	while (token != NULL){
    	if(strcasecmp(token,keyWord) == 0){	
    	printf("Match found for \'%s\': %s wrote: \"%s\"\n",keyWord,copy->user,copy->text);
    	count++;
    }
        token = strtok(NULL, " .,?!");
    }
 	
 }
 copy = copy->next; 
}
if (count == 0)
	{
		//printf("No matches found for \'%s\'.\n", keyWord);
		return 0;
	}
	else{
		return 1;
	}
 	
}
