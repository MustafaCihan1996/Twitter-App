#include <strings.h>
#include "headerA3.h"

char *stopwords[30] = {"a","an","and","are","as","at","be","by",
					"for","from","has","he","in","is","it","its",
					"of","on","that","the","to","was","were","will","with"};
void countStopWords(tweet * tweetList){
	char line[MAXTWEETSIZE];
	int count = 0;
	int countTwo = 0;
	tweet *copy;
	copy = tweetList;
	while(copy != NULL){
	strcpy(line,copy->text);	
 	char *token = strtok(line," .,?!");
 	int i;
 	while(token != NULL){
 	for(i = 0; i<25; i++){
	 	
 	if(strcasecmp(token,stopwords[i]) == 0){
 		count++;
	 }
	}
	token = strtok(NULL, " .,?!"); 

} 
	countTwo++;
	copy = copy->next;
}
	printf("Across %d tweets, %d stop words were found.\n",countTwo,count);
	return;	
}
