A3_output: addnode.o countStopWords.o createTweets.o deleteTweets.o displayTweets.o loadTweets.o mainA3.o saveTweets.o searchTweets.o
	gcc -Wall -std=c99 addnode.o countStopWords.o createTweets.o deleteTweets.o displayTweets.o loadTweets.o mainA3.o saveTweets.o searchTweets.o -o A3_output

addnode.o: addnode.c headerA3.h
	gcc -Wall -std=c99 -c  addnode.c

countStopWords.o: countStopWords.c headerA3.h
	gcc -Wall -std=c99 -c countStopWords.c

createTweets.o: createTweets.c headerA3.h
	gcc -Wall -std=c99 -c createTweets.c

deleteTweets.o: deleteTweets.c headerA3.h
	gcc -Wall -std=c99 -c deleteTweets.c

displayTweets.o: displayTweets.c headerA3.h
	gcc -Wall -std=c99 -c displayTweets.c

loadTweets.o: loadTweets.c headerA3.h
	gcc -Wall -std=c99 -c loadTweets.c

mainA3.o: mainA3.c headerA3.h
	gcc -Wall -std=c99 -c mainA3.c

saveTweets.o: saveTweets.c headerA3.h
	gcc -Wall -std=c99 -c saveTweets.c

searchTweets.o: searchTweets.c headerA3.h
	gcc -Wall -std=c99 -c searchTweets.c

clean:
		rm *.o A3_output	
