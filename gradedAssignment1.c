/*
Program     : gradedAssignment1
FileName    : main.c
Author      : Stuart H
Date	    : Feb 2015

Description : This program is graded assignment one of "Intro to Programming 
			  Using C" offered at the UMBC Training Center, Columbia. It is
			  a guessing game. A user will be prompted to make a guess at an
			  integer between 1 and 100 inclusively. Should the user guess
			  correctly, a congratulatory message will be displayed and the
			  program will exit. Otherwise, the user will be told how close
			  they are using the below key. The user has 10 tries.
					- Within 5   : "Hot
					- Within 12  : "Warm"
					- Within 30  : "Cold"
					- Outside 30 : "Frigid"
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CORRECT_ANSWER 77
#define HOT 5
#define WARM 12
#define COLD 30



int welcomeScreen(void) {
	/*
	This function prints a generic welcome screen
	with directions
	*/

	printf("***********************************************\n");
	printf("**    Welcome to a game of chance (kinda)    **\n");
	printf("**                                           **\n");
	printf("**    You have ten attempts to guess the     **\n");
	printf("**    number I am thinking of. Use the key   **\n");
	printf("**    below to calibrate your guesses. Oh,   **\n");
	printf("**    the number I am thinking of is between **\n");
	printf("**    1 and 100, inclusively. Good Luck !    **\n");
	printf("**                                           **\n");
	printf("**    - Within 5   : Hot                     **\n");
	printf("**    - Within 12  : Warm                    **\n");
	printf("**    - Within 30  : Cold                    **\n");
	printf("**    - Outside 30 : Frigid                  **\n");
	printf("***********************************************\n\n");

	return 0;
}

int numberGuesser(void) {
	/*
	This function controls the number guessing game.
	The if statements below are pretty nasty to look at,
	mainly because of the length of variable names.
	*/

	int usersGuess;												// init integers to hold guesses
	int nrOfGuesses;											// number of guesses
	bool guessedCorrectly = false;								// and a boolean to check later

	for (nrOfGuesses = 1; nrOfGuesses <= 10; nrOfGuesses++) {	// loop through 10 times
		
		printf("Guess #%d: ", nrOfGuesses);
		scanf_s("%d", &usersGuess);								// gather guesses

		if (usersGuess == CORRECT_ANSWER) {						// if the guess is correct
			printf("%d is correct!\n",usersGuess);
			printf("It only took you %d tries!\n", nrOfGuesses);// congratulate them
			guessedCorrectly = true;							// set guessed correctly to true
			break;												// and break (sorry, purists)
		}

		if ((usersGuess >= (CORRECT_ANSWER - HOT)) &&			// if you're within 5
			(usersGuess <= (CORRECT_ANSWER + HOT))){

			printf("Your guess is Hot!\n");						// print hot
		}
		else if ((usersGuess >= (CORRECT_ANSWER - WARM)) &&	    // else if within 12
				 (usersGuess <= (CORRECT_ANSWER + WARM))){

			printf("Your guess is Warm!\n");					// print warm
		}
		else if ((usersGuess >= (CORRECT_ANSWER - COLD)) &&		// else if within 30
				 (usersGuess <= (CORRECT_ANSWER + COLD))){

			printf("Your guess is Cold.\n");					// print cold
		}
		else {													// otherwise
			printf("Your guess is Frigid.\n");					// print frigid
		}	
	}

	if (!guessedCorrectly) {									// if they exhausted their ten tries
		printf("Everyone has their strengths...");
		printf("Sorry about your luck.\n");						// send them on their way
	}
	
	return 0;
}


int main(int argc, char *argv[]) {
	/*
	The main function controls the program flow
	*/

	system("cls");												// clear out any garbage on the screen

	int keepPlaying = 1;										// init an int to handle truth	

	while (keepPlaying) {										// so long as the user wats to keep playing
		welcomeScreen();										// print the welcome screen
		numberGuesser();										// run the guessing game

		printf("\n\nPlay again? (0 to quit) \n");				// and ask if they want to play again
		scanf_s("%d", &keepPlaying);							// store value in truth integer

		system("cls");											// clear the screen
	}

	return 0;
}
