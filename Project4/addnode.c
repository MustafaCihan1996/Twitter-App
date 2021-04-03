#include "headerA3.h"

void addNodeToList(tweet**tweetList,tweet * node){
	tweet *head = *tweetList;
	
	if(head == NULL){
		*tweetList = node;
		return;
	}
	while(head->next){
		head = head->next;
	}
	head->next = node;
	
}
