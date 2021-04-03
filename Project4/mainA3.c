#include <stdio.h>
#include "headerA3.h"

int main(int argc, char *argv[]){
	char line[50];
	int choose = 126;
	tweet * tweetList = NULL;
	tweet * newTweet;
	while(choose !=8){
	printf("1. Create a new tweet\n");
	printf("2. Display tweets\n");
	printf("3. Search a tweet by (keyword)\n");
	printf("4. Find how many words are ""stop words""\n");
	printf("5. Delete the nth tweet\n");
	printf("6. Save tweets to a file\n");
	printf("7. Load tweets from a file\n");
	printf("8. Exit\n");
	printf("Choose a menu option: ");
	fgets(line,BUFFERSIZE,stdin);
	choose = atoi(line);
	if(choose == 1){
	   newTweet = createTweet(tweetList);
	   addNodeToList( &tweetList, newTweet);		
	}
	if(choose == 2){
	  displayTweets(tweetList);	
	}
	if(choose == 3){
	  searchTweetsByKeyword(tweetList);	
	}
	if(choose == 4){
	  countStopWords(tweetList);		
	}
	if(choose == 5){
	  deleteTweet(&tweetList);		
	}
	if(choose == 6){
	  saveTweetsToFile(tweetList);		
	}
	if(choose == 7){
	  loadTweetsFromFile(&tweetList);	
	}
	
	}
		return 0;

}
