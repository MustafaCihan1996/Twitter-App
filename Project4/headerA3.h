#include <stdio.h>
#include <stdlib.h>
#include <string.h>	

#define BUFFERSIZE 256
#define MAXUSERNAMESIZE 50
#define MAXTWEETSIZE 140
#define MAXFILENAMESIZE 250



typedef struct microtweet{
    int id; 				//unique integer value	
    char user[MAX_USER_NAME_SIZE + 1]; 			// the userid / username of the person who wrote the tweet
    char text[MAX_TWEET_SIZE + 1]; 		// the text of the tweet
   
    struct microtweet *next;  //dynamic connection to the next tweet
}tweet;



// menu functions 
tweet * createTweet( tweet * tweetList);

void displayTweets(tweet * tweetList);

int searchTweetsByKeyword(tweet * tweetList);

void countStopWords(tweet * tweetList);

void deleteTweet(tweet ** tweetList);

void saveTweetsToFile(tweet * tweetList);

void loadTweetsFromFile(tweet ** tweetList);

// linked list function - required after you create a tweet or load tweets from a file
void addNodeToList(tweet**tweetList,tweet * node);


