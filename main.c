#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

char* message = "Test message...";

enum MessagePrintState
{
	INIT,
	GIBBERISH,
	QUOTE,
	ART,
};

void printQuote()
{
	int i;
	for (i = 0; i < strlen(message); i++)
	{
		printf("%c", message[i]);
		fflush(stdout);
		usleep(100 * 1000);
	}

	printf("\n");
}

void printGibberish()
{
	//
}

void printAsciiArt()
{
	//
}

int main (int argc, char* argv[])
{
	while(1)
	{
		//
	}

	return 0;
}

