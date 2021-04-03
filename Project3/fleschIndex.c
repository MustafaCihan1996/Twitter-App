#include "fleschIndex.h"


char * readFile (char * filename){
	int n_lines = 0;
	char *text = NULL;
	char buf[MAX_LINE_SIZE];
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return NULL;
	}
	while(fgets(buf, MAX_LINE_SIZE, fp)){
		n_lines++;
	}
	fseek(fp, 0, SEEK_SET);
	text = calloc(n_lines * MAX_LINE_SIZE, sizeof(char));
	while(fgets(buf, MAX_LINE_SIZE, fp)){
		strcat(text, buf);
	}
	
	fclose(fp);

	return text;
}

int calculateFleschIndex(int syllables, int words, int sentences){
	int index = 0;
	int sylWord = syllables / words;
	int wordSen = words / sentences;

	index = 206.835 - 84.6 * sylWord - 1.015 * wordSen + 0.5;
	return index;
}

void outputFormattedFleschScores(int syllables, int words, 
									int fleshIndex, int sentenceCount){
	printf("Flesch Index = %d\n", fleshIndex);
	printf("Syllable Count = %d\n", syllables);
	printf("Word Count = %d\n", words);
	printf("Sentence Count = %d\n", sentenceCount);

	return;
}

int countWords(char *s){
	char *copy = NULL;
	copy = calloc(strlen(s)+1, sizeof(char));
	strcpy(copy, s);

	int num = 0;
	char *token = strtok(copy, " \n\r");
    while (token != NULL) {
    	num++;
        token = strtok(NULL, " \n\r");
    }
	free(copy);

	return num;
}

int countSentences(char *s){
	char *copy = NULL;
	copy = calloc(strlen(s)+1, sizeof(char));
	strcpy(copy, s);

	int num = 0;
	char *token = strtok(copy, " \n\r");
    while (token != NULL) {
    	if (strchr(".:;?!", token[strlen(token)-1]))
    	{
    		num++;
    	}
        token = strtok(NULL, " \n\r");
    }
	free(copy);

	return num;
}

int countSyllables(char *s){
	char *copy = NULL;
	int numSyl = 0;
	int wordSyl = 0;
	
	copy = calloc(strlen(s)+1, sizeof(char));
	strcpy(copy, s);
	char *token = strtok(copy, " \n\r");
    while (token != NULL) {
        wordSyl = 0;
        char *s = token;
        while(*s){
        	if (strchr("aeiouyAEIOUY", *s))
        	{
        		wordSyl++;
        		if (strchr("eE", *s) && *(s+1) == '\0')
        		{
        			wordSyl--;
        		}
        		while(*s && strchr("aeiouyAEIOUY", *s)){
        			s++;
        		}
        	}
        	if(*s){
        		s++;
        	}
        }
        if (wordSyl == 0)
        {
        	wordSyl = 1;
        }
        numSyl += wordSyl;
        token = strtok(NULL, " \n\r");
    }
	free(copy);

    return numSyl;
}




