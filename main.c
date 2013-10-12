#define MAX_STRING_LENGTH 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

char* message = "Test message...";

typedef enum
{
	INIT,
	GIBBERISH,
	QUOTE,
	ART,
} MessagePrintState;

MessagePrintState state;

char* quotes[201];

void loadData(char* datafile)
{
	FILE* file;
	file = fopen(datafile, "r");

	char* buffer = calloc(250 * sizeof(char), 1);

	int bufferCount = 0;

	if (file != NULL)
	{
		printf("LOADING DATA...\n");

		while (feof(file) == 0)
		{
			fgets(buffer, MAX_STRING_LENGTH, file);
			quotes[bufferCount] = buffer;
			buffer = calloc(250 * sizeof(char), 1);
			bufferCount++;
		}

		fclose(file);
	}
}

void printQuote()
{
	int randomQuote = rand() % 200;
	char* message = quotes[randomQuote];

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
	state = INIT;

	while(1)
	{
		switch (state)
		{
			case INIT:
				loadData("data.txt");
				printf("SUPER COOL TYPING PROGRAM\nSTARTUP!\n");
				state = QUOTE;
				break;
			case GIBBERISH:
				break;
			case QUOTE:
				printQuote();
				break;
			case ART:
				break;
		}
	}

	return 0;
}

