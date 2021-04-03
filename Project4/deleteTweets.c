#include "headerA3.h"

void deleteTweet(tweet ** tweetList){
	int count = 0;
	int whichOne;
	tweet *temp = *tweetList;
	tweet *head = *tweetList;
	head = *tweetList;
	while(head){
		head = head->next;
		count++;
	}
	
	if(count == 0){
	  printf("There is no tweet\n");	
	}
	else{
	  printf("Currently there are %d tweets.\n",count);
	}
	  printf("Which tweet do you wish to delete-enter a value between 1 and %d: ",count);
	  scanf("%d",&whichOne);
	  if(whichOne < 1 || whichOne > count){
	  	printf("You entered invalid value\n");
	  	return;
	  }
	 if(whichOne == 1){
	 	temp = *tweetList;
	 	*tweetList = temp->next;
	 }
	 else{
	 head = *tweetList;	
	 int i;
	 for(i = 1; i<whichOne-1;i++){
	     head= head->next;
	 }
	 temp = head->next;
	 head->next=temp->next;
	 
}
printf("Tweet %d deleted. There are now %d tweets left.\n",whichOne,count-1);
free(temp);
return;
}
