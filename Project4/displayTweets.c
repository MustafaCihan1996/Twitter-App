#include "headerA3.h"

void displayTweets(tweet * tweetList){
	if (tweetList == NULL)
	{
		printf("There are no tweets to show.\n");
		return;
	}
	while(tweetList){
	printf("%d: Created by %s: %s\n",tweetList->id,tweetList->user,tweetList->text);
    tweetList = tweetList->next;
	}
	return;
}
