
#include "fleschIndex.h"

int main(int argc, char const *argv[])
{

	char fname[MAX_LINE_SIZE];
	char *text;
	int words, syllables, sentenceCount, fleschIndex;

	if (argc != 2)
	{
		fprintf(stderr, "%s\n", "Usage: ./fleschIndex <filename>");
		return -1;
	}
	strcpy(fname, argv[1]);
	text = readFile(fname);
	if (text == NULL)
	{
		fprintf(stderr, "%s: \"%s\"\n", "Error opening file", argv[1]);
		return -1;
	}
	words = countWords(text);
	syllables = countSyllables(text);
	sentenceCount = countSentences(text);
	fleschIndex = calculateFleschIndex(syllables, words, sentenceCount);
	outputFormattedFleschScores(syllables, words, fleschIndex, sentenceCount);
	
	free(text);

	return words;
}
