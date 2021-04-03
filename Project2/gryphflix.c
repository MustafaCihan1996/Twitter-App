#include "gryphflix.h"


int get_max(int arr[], int size){

	int max;
	max = arr[0];

	for (int i = 0; i < size; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

int get_min(int arr[], int size){

	int min = arr[0];

	for (int i = 0; i < size; ++i)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	return min;
}

FILE *openFileForReading(char *fileName){
	
	FILE *file = fopen(fileName, "r");

	if (file == NULL)
	{
		return NULL;
	}

	return file;
}

int readMovies(FILE *file, char movieNames[NUMBER_MOVIES][MAX_STR]){
	
	char line_buf[MAX_STR];
	int N_read_lines;
	char *newline_pos;


	if (file == NULL)
	{
		return 0;
	}

	N_read_lines = 0;

	while (fgets(line_buf, MAX_STR, file) != NULL){

		if (N_read_lines >= NUMBER_MOVIES)
		{
			return 0;
		}

		newline_pos = strchr(line_buf, '\n');

		if (newline_pos != NULL){

	    	*newline_pos = '\0';
		}

		strcpy(movieNames[N_read_lines], line_buf);

		N_read_lines++;

	}
	if (N_read_lines < NUMBER_MOVIES)
	{
		return 0;
	}

	return 1;
}

int readReviews(FILE *file, struct reviewStruct reviews[NUMBER_REVIEWERS]){
	
	char line_buf[MAX_STR];
	char *token;
	char *newline_pos;
	int N_read_lines;
	int N_feedback;


	if (file == NULL)
	{
		return 0;
	}

	N_read_lines = 0;

	while (fgets(line_buf, MAX_STR, file) != NULL){

		if (N_read_lines >= NUMBER_REVIEWERS)
		{
			return 0;
		}

		newline_pos = strchr(line_buf, '\n');
		if (newline_pos != NULL){

	    	*newline_pos = '\0';
		}

	    token = strtok(line_buf, " ");
	    strcpy(reviews[N_read_lines].reviewer, token);
	    N_feedback = 0;

	    while (token != NULL) {
	token = strtok(NULL, " ");
	    	if (strcmp(token, "Y") == 0 || strcmp(token, "y") == 0)
	    	{
	    		reviews[N_read_lines].feedback[N_feedback] = 1;
	    	}
	    	else if (strcmp(token, "N") == 0 || strcmp(token, "n") == 0)
	    	{
	    		reviews[N_read_lines].feedback[N_feedback] = 0;
	    	}

	        N_feedback++;

	        if (N_feedback >= 3)
	        {
	        	break;
	        }
	    }

		N_read_lines++;
	}

	if (N_read_lines < NUMBER_REVIEWERS)
	{
		return 0;
	}

	return 1;
}

int getMostCriticalReviewers(struct reviewStruct reviews[NUMBER_REVIEWERS],
								char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR]){
	int min_rating;
	int ratings[NUMBER_REVIEWERS];
    
	for (int i = 0; i < NUMBER_REVIEWERS; ++i)
	{
		ratings[i] = 0;
		for (int j = 0; j < NUMBER_MOVIES; ++j)
		{
			ratings[i] += reviews[i].feedback[j];
		}
	}

	min_rating = get_min(ratings, NUMBER_REVIEWERS);

	int num_critics = 0;
	for (int i = 0; i < NUMBER_REVIEWERS; ++i)
	{
		if (ratings[i] == min_rating)
		{
			strcpy(mostCriticalReviewers[num_critics], reviews[i].reviewer);
			num_critics++;
		}
	}

	return num_critics;
}

int getMostRecommendedMovies(const char movies[NUMBER_MOVIES][MAX_STR],
								const struct reviewStruct reviews[NUMBER_REVIEWERS],
									char mostRecommendedMovies[NUMBER_REVIEWERS][MAX_STR]){
	int max_rating;
	int ratings[NUMBER_MOVIES];

	for (int i = 0; i < NUMBER_MOVIES; ++i)
	{
		ratings[i] = 0;
		for (int j = 0; j < NUMBER_REVIEWERS; ++j)
		{
			ratings[i] += reviews[j].feedback[i];
		}
	}

	max_rating = get_max(ratings, NUMBER_MOVIES);

	int num_rec_movies = 0;
	for (int i = 0; i < NUMBER_MOVIES; ++i)
	{
		if (ratings[i] == max_rating)
		{
			strcpy(mostRecommendedMovies[num_rec_movies], movies[i]);
			num_rec_movies++;
		}
	}



	return num_rec_movies;
}
int predictMovie(const char movie[MAX_STR]){

	char *token;
	int prediction;
	int n_words;
	int n_even_char_words;
	int first_num_char;
	int same_num_char;		// equals to 1 if all words in a movie title
							// have the same number of characters, 0 otherwise
	char movie_cpy[MAX_STR];
	for (int i = 0; i < MAX_STR; ++i)
	{
		movie_cpy[i] = movie[i]; 
	}
	
	token = strtok(movie_cpy, " ");
	n_words = 0;
	n_even_char_words = 0;
	same_num_char = 1;
	if (token != NULL)
	{
		first_num_char = strlen(token);
		if (strlen(token) % 2 == 0)
		{
			n_even_char_words++;
		}
	}
	while (token != NULL) {
    	token = strtok(NULL, " ");
		n_words++;
		if (token != NULL)
		{
			if (strlen(token) != first_num_char)
			{
				same_num_char = 0;
			}
			if (strlen(token) % 2 == 0)
			{
				n_even_char_words++;
			}
		}
	}
	prediction = 0;

	if (n_words > 2)
	{
		prediction -= 1;
	}
	if (n_words == 1)
	{
		prediction -= 2;
	}
	if (n_even_char_words > 1)
	{
		prediction += 1;
	}
	if (same_num_char == 1)
	{
		prediction += 2;
	}
	if (prediction < -2)
	{
		prediction = -2;
	}
	if (prediction > 2)
	{
		prediction = 2;
	}


	return prediction;
}
int enumerateMovie(const char movie[MAX_STR], int charCounts[MAX_WORDS]){
   char copy[MAX_STR];
   strcpy(copy,movie);
   
  
   const char s[2] = " ";
   char *token;
   int i=0;
   token = strtok(copy, s);

   while( token != NULL ) {
      charCounts[i] = strlen(copy);
      printf("%ld ",strlen(token));
      token = strtok(NULL, s);
    i++; 
    
   }

   return i;
}
