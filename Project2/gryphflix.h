/*
 Student Name: Mustafa Cihan
 Student ID: 1113713
 Due Date: 1/29/2021
 Course: CIS*2500
 I have exclusive control over this submission via my password.
 By including this header comment, I certify that:
 1) I have read and understood the policy on academic integrity.
 2) I have completed Moodle's module on academic integrity.
 3) I have achieved at least 80% on the academic integrity quiz
 I assert that this work is my own. I have appropriate acknowledged
 any and all material that I have used, be it directly quoted or
 paraphrased. Furthermore, I certify that this assignment was written
 by me in its entirety.
*/
#include <stdio.h>
#include <string.h>

#define NUMBER_REVIEWERS 10		// represents the number of reviewers
#define NUMBER_MOVIES 3 		// represents the number of movies
#define MAX_STR 50 				// represent the maximum length of a string
#define MAX_WORDS 10			// represents the maximum number of words in a movie title


struct reviewStruct {

	char reviewer[MAX_STR];			// e.g "Jason"
	int feedback[NUMBER_MOVIES];	// e.g {1, 0, 0}
};


FILE *openFileForReading(char *fileName);
int readMovies(FILE *file, char movieNames[NUMBER_MOVIES][MAX_STR]);
int readReviews(FILE *file, struct reviewStruct reviews[NUMBER_REVIEWERS]);
int getMostCriticalReviewers(struct reviewStruct reviews[NUMBER_REVIEWERS],
								char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR]);
int getMostRecommendedMovies(const char movies[NUMBER_MOVIES][MAX_STR],
								const struct reviewStruct reviews[NUMBER_REVIEWERS],
									char mostRecommendedMovies[NUMBER_REVIEWERS][MAX_STR]);
int enumerateMovie(const char movie[MAX_STR], int charCounts[MAX_WORDS]);
int predictMovie(const char movie[MAX_STR]);
int get_max(int arr[], int size);
int get_min(int arr[], int size);

