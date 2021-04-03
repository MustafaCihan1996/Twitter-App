#include "givenA2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

void createInitialBoard(char board[N][N])
{

	int i;
	int j;
	for( i = 0; i<=2; i++)
	{
		for( j = 0; j<=2; j++)
	{
			board[i][j] = '?';
	}
	
    } 
    printf("\n");
    printf("   1   2   3\n\n");
    printf("1  %c | %c | %c\n", board[0][0],board[0][1],board[0][2]);
	printf("  ------------\n");
    printf("2  %c | %c | %c\n", board[1][0],board[1][1],board[1][2]);
    printf("  ------------\n");
    printf("3  %c | %c | %c\n", board[2][0],board[2][1],board[2][2]);	
    
}    
void readUserMove(int *userRow, int *userCol, int *stepsWon)
{ 
	printf("Your move enter numbers between 1 and 3\n\n");
	printf("Enter a row number: ");
	scanf("%d",userRow);
	printf("Enter a column number: ");
	scanf("%d",userCol);
	*stepsWon = *stepsWon+1;
}
void printCurrentBoard(char board[N][N])
{  
    printf("Current board now is:\n\n");
    printf("\n");
    printf("   1   2   3\n\n");
    printf("1  %c | %c | %c\n", board[0][0],board[0][1],board[0][2]);
	printf("  ------------\n");
    printf("2  %c | %c | %c\n", board[1][0],board[1][1],board[1][2]);
    printf("  ------------\n");
    printf("3  %c | %c | %c\n", board[2][0],board[2][1],board[2][2]);
    
}
int isInputValid(int entered, int minimum, int maximum)
{
	if(entered >= minimum && entered <= maximum ){
		return 1;
	}
	else{
		return 0;
	}
}
int gameWon(char board[N][N],char m)
{
   if(board[0][0] == m && board[0][1] == m && board[0][2] == m)
   {
   	return 1;
   }
 
   if(board[1][0] == m && board[1][1] == m && board[1][2] == m)
   {
   	return 1;
   }
   if(board[2][0] == m && board[2][1] == m && board[2][2] == m)
   {
   	return 1;
   }
   if(board[0][0] == m && board[1][0] == m && board[2][0] == m)
   {
   	return 1;
   }
   if(board[0][1] == m && board[1][1] == m && board[2][1] == m)
   {
   	return 1;
   }
   if(board[0][2] == m && board[1][2] == m && board[2][2] == m)
   {
   	return 1;
   }
   if(board[0][0] == m && board[1][1] == m && board[2][2] == m)
   {
   	return 1;
   }
   if(board[0][2] == m && board[1][1] == m && board[2][0] == m)
   {
   	return 1;
   }
   else
   {
     return 0;
   }
    										
}
int isBoardFull(char board[N][N]){
	int i;
	int j;
	for( i = 0; i<=2; i++)
	{
		for( j = 0; j<=2; j++)
	{
	  		if(board[i][j] == '?'){
	  			return 0;
	  		} 
    }
    }
    return 1;
}
int getComputerMove(char board[N][N], int *computerRow, int *computerCol, int userRow, int userCol){
	    int winningSpot = 0;
    
    winningSpot = computerPlaysToWin(board, computerRow, computerCol);
    
    /*
     if the computer does not find a winning spot, then it either play randomly or blocks
     */
    
    if (!winningSpot)
    {
        // comment the next line if you are attempting the 2% functionality
       // computerPlaysRandom(computerRow, computerCol);
        
        // uncomment the next few  lines if you are attempting the 2% functionality
        int blocked = 0;
         
         blocked = computerPlaysToBlock(board, computerRow, computerCol);
         if (blocked == 0) {
         computerPlaysRandom(computerRow, computerCol);
         }
         
         return blocked;
         
    }
    return winningSpot;
}
void computerPlaysRandom(int *computerRow , int *computerCol){
     *computerRow = rand()%3;
     *computerCol = rand()%3;	
     
}
int convert(char c){
	if(c=='X'){
		return 1;
	}
    if(c=='O'){
		return 4;
	}
	return 0;
}
int computerPlaysToWin(char board[N][N], int *computerRow , int *computerCol){
	
    if(convert(board[0][0]) + convert(board[0][1]) + convert(board[0][2]) == 8)
   {
   	    int i;
   	    int j;
   	    	for(i = 0; i<=0; i++)
			{
   	    		for(j = 0; j<=2; j++)
			   {
   	    			if(board[i][j] == '?'){
   	    				*computerRow = i;
     					*computerCol = j;	
				   }
			   }
		   }
   	return 1;
   }
    if(convert(board[1][0]) + convert(board[1][1]) + convert(board[1][2]) == 8)
   {
   	    int i;
   	    int j;
   	    	for(i = 1; i<=1; i++)
			{
   	    		for(j = 0; j<=2; j++)
			   {
   	    			if(board[i][j] == '?'){
   	    				*computerRow = i;
     					*computerCol = j;	
				   }
			   }
		   }
   	return 1;
   }
    if(convert(board[2][0]) + convert(board[2][1]) + convert(board[2][2]) == 8)
   {
   	    int i;
   	    int j;
   	    	for(i = 2; i<=2; i++)
			{
   	    		for(j = 0; j<=2; j++)
			   {
   	    			if(board[i][j] == '?'){
   	    				*computerRow = i;
     					*computerCol = j;	
				   }
			   }
		   }
   	return 1;
   }
    if(convert(board[0][0]) + convert(board[1][0]) + convert(board[2][0]) == 8)
   {
   	    int i;
   	    int j;
   	    	for(i = 0; i<=2; i++)
			{
   	    		for(j = 0; j<=0; j++)
			   {
   	    			if(board[i][j] == '?'){
   	    				*computerRow = i;
     					*computerCol = j;	
				   }
			   }
		   }
   	return 1;
   }
    if(convert(board[0][1]) + convert(board[1][1]) + convert(board[2][1]) == 8)
   {
   	    int i;
   	    int j;
   	    	for(i = 0; i<=2; i++)
			{
   	    		for(j = 1; j<=1; j++)
			   {
   	    			if(board[i][j] == '?'){
   	    				*computerRow = i;
     					*computerCol = j;	
				   }
			   }
		   }
   	return 1;
   }
    if(convert(board[0][2]) + convert(board[1][2]) + convert(board[2][2]) == 8)
   {
   	    int i;
   	    int j;
   	    	for(i = 0; i<=2; i++)
			{
   	    		for(j = 2; j<=2; j++)
			   {
   	    			if(board[i][j] == '?'){
   	    				*computerRow = i;
     					*computerCol = j;	
				   }
			   }
		   }
   	return 1;
   }
    if(convert(board[0][0]) + convert(board[1][1]) + convert(board[2][2]) == 8)
   {
   	    int i;
   	    	for(i = 0; i<=2; i++)
			{
   	    			if(board[i][i] == '?'){
   	    				*computerRow = i;
     					*computerCol = i;	
				   }
			   
		   }
   	return 1;
   }
    if(convert(board[0][2]) + convert(board[1][1]) + convert(board[2][0]) == 8)
   {	   
   	  	if(board[0][2] == '?' )
		{
   	    	*computerRow = 0;
     		*computerCol = 2;	
		}
			       
   	    if(board[1][1] == '?' )
		{
   	    	*computerRow = 1;
     		*computerCol = 1;	
	    }
		          
   	    if(board[2][0] == '?' )
		{
   	    	*computerRow = 2;
     		*computerCol = 0;	
		}
		   
   	return 1;
   }
   return 0;	
}
int convertTwo(char d)
{
	if(d=='X')
	{
		return 4;
	}
    if(d=='O')
	{
		return 1;
	}
	return 0;
}
int computerPlaysToBlock(char board[N][N], int *computerRow , int *computerCol ){
	 if(convertTwo(board[0][0]) + convertTwo(board[0][1]) + convertTwo(board[0][2]) == 8)
   {
   	    int i;
   	    int j;
   	    	for(i = 0; i<=0; i++)
			{
   	    		for(j = 0; j<=2; j++)
			   {
   	    			if(board[i][j] == '?'){
   	    				*computerRow = i;
     					*computerCol = j;	
				   }
			   }
		   }
   	return 1;
   }
    if(convertTwo(board[1][0]) + convertTwo(board[1][1]) + convertTwo(board[1][2]) == 8)
   {
   	    int i;
   	    int j;
   	    	for(i = 1; i<=1; i++)
			{
   	    		for(j = 0; j<=2; j++)
			   {
   	    			if(board[i][j] == '?'){
   	    				*computerRow = i;
     					*computerCol = j;	
				   }
			   }
		   }
   	return 1;
   }
    if(convertTwo(board[2][0]) + convertTwo(board[2][1]) + convertTwo(board[2][2]) == 8)
   {
   	    int i;
   	    int j;
   	    	for(i = 2; i<=2; i++)
			{
   	    		for(j = 0; j<=2; j++)
			   {
   	    			if(board[i][j] == '?'){
   	    				*computerRow = i;
     					*computerCol = j;	
				   }
			   }
		   }
   	return 1;
   }
    if(convertTwo(board[0][0]) + convertTwo(board[1][0]) + convertTwo(board[2][0]) == 8)
   {
   	    int i;
   	    int j;
   	    	for(i = 0; i<=2; i++)
			{
   	    		for(j = 0; j<=0; j++)
			   {
   	    			if(board[i][j] == '?'){
   	    				*computerRow = i;
     					*computerCol = j;	
				   }
			   }
		   }
   	return 1;
   }
    if(convertTwo(board[0][1]) + convertTwo(board[1][1]) + convertTwo(board[2][1]) == 8)
   {
   	    int i;
   	    int j;
   	    	for(i = 0; i<=2; i++)
			{
   	    		for(j = 1; j<=1; j++)
			   {
   	    			if(board[i][j] == '?'){
   	    				*computerRow = i;
     					*computerCol = j;	
				   }
			   }
		   }
   	return 1;
   }
    if(convertTwo(board[0][2]) + convertTwo(board[1][2]) + convertTwo(board[2][2]) == 8)
   {
   	    int i;
   	    int j;
   	    	for(i = 0; i<=2; i++)
			{
   	    		for(j = 2; j<=2; j++)
			   {
   	    			if(board[i][j] == '?'){
   	    				*computerRow = i;
     					*computerCol = j;	
				   }
			   }
		   }
   	return 1;
   }
    if(convertTwo(board[0][0]) + convertTwo(board[1][1]) + convertTwo(board[2][2]) == 8)
   {
   	    int i;
   	    	for(i = 0; i<=2; i++)
			{
   	    			if(board[i][i] == '?'){
   	    				*computerRow = i;
     					*computerCol = i;	
				   }
			   
		   }
   	return 1;
   }
    if(convertTwo(board[0][2]) + convertTwo(board[1][1]) + convertTwo(board[2][0]) == 8)
   {	   
   	  	if(board[0][2] == '?' )
		{
   	    	*computerRow = 0;
     		*computerCol = 2;	
		}
			       
   	    if(board[1][1] == '?' )
		{
   	    	*computerRow = 1;
     		*computerCol = 1;	
	    }
		          
   	    if(board[2][0] == '?' )
		{
   	    	*computerRow = 2;
     		*computerCol = 0;	
		}
		   
   	return 1;
   }
   return 0;	
}
int memberOf(int value, int someArray[N]){
	int i;
	for(i = 0; i< N; i++){
		if(value == someArray[N]){
			return 1;
		}
	}
	return 0;
}
void all_sums(char board[N][N], int a[N], int b[N], int *c, int *d){
	printf("The sum of row 1 one is %d", board[0][0]+board[0][1]+board[0][2]);
	printf("The sum of row 2 one is %d", board[1][0]+board[1][1]+board[1][2]);
	printf("The sum of row 3 one is %d", board[2][0]+board[2][1]+board[2][2]);
	printf("The sum of column 1 one is %d", board[0][0]+board[1][0]+board[2][0]);
	printf("The sum of column 2 one is %d", board[0][1]+board[1][1]+board[2][1]);
	printf("The sum of column 3 one is %d", board[0][2]+board[1][2]+board[2][2]);
	printf("The sum of  diagonal left one is %d", board[0][0]+board[1][1]+board[2][2]);
    printf("The sum of  diagonal right one is %d", board[0][2]+board[1][1]+board[2][0]);
}

int main(){
    
    int userRow, userCol, computerRow, computerCol;
    int taken;
    int count = 1;
    int stepsWon = 0;
    
    char board[N][N];
    char winner = 'N';
    
    srand((int) time(0));
    
    printf ("This tic-tac-toe board is of size %d by %d\n", N, N);
    
    printf ("You are using symbol X and the computer program is using symbol O\n");
    
    printf ("Here is the board - spaces are indicated by a ?\n");
    
    createInitialBoard (board);
    
    while ((winner != 'Y') && !(isBoardFull(board)))
    {
        taken = 0;
        
        while (!(taken))
        {
            readUserMove(&userRow, &userCol, &stepsWon);
            printf("You chose row %d and column %d \n", userRow, userCol);
            
            while (!isInputValid(userRow, 1, N) || !isInputValid(userCol, 1, N))
            {
                printf("That's is an invalid row or column number - try again\n");
                readUserMove(&userRow, &userCol, &stepsWon);
                printf("You chose row %d and column %d \n", userRow, userCol);
            }
            
            if (board[userRow-1][userCol-1] == '?')
            {
                board[userRow-1][userCol-1] = 'X';
                taken = 1;
                count++;
                
            }
            else
            {
                taken = 0;
                printf("That spot is taken - please try another one\n");
            }
        }
        
        if (gameWon(board, 'X'))   //user won
        {
            printf("Congrats - you won against the computer :) in %d steps\n", stepsWon);
            winner = 'Y';
        }
        
        else  if (!(isBoardFull(board)))            //check computer's move if the board is not yet full
        {
            taken = 0;
            
            while (!(taken))
            {
                taken = getComputerMove(board, &computerRow, &computerCol, userRow-1, userCol-1);
                
                if (taken) {
                    break;
                }
                
                getchar();
                
                if (board[computerRow][computerCol] == '?')
                {
                    board[computerRow][computerCol] = 'O';
                    taken = 1;
                    
                }
                else
                {
                    taken = 0;
                    //printf("That spot is taken - computer - try another one\n");
                }
            }
            printf("Computer chose row %d and column %d \n", computerRow+1, computerCol+1);
            if (gameWon(board, 'O'))
            {
                printf("Oh the computer won this time :(( think hard next time\n");
                winner = 'Y';
            }
        }
        
        printCurrentBoard (board);
        
        if (winner != 'Y') {
           printf("Enter to continue \n");
        }
        getchar();
        
    } //end of while
    
    if (winner != 'Y') {
       printf("Game was a tie - no winner!\n\n");
    }
    return 0;
}



