//  Name        :   Charles Dobson
//  Date        :   26 April 2019
//  Description :   This program is an implementation of a circular buffer. It
//                  stores and accesses values in a FIFO manner. It gets user input
//                  to write new values to the buffer and reads these values by
//                  printing them to the screen.



//  LIBRARIES
#include <stdio.h>
#include <stdlib.h>



//  CONSTANTS
#define		SIZE_OF_BUFFER		    8	// Maximum size of buffer
#define		MAX_LENGTH_OF_STRING	81  // Arbitrary number for temporary strings
#define		SUCCESS			        0
#define		FAILURE			        -1
#define		EXIT_LOOP               1



//  PROTOTYPES
void	displayMainMenu(void);
int		getNumber(int* pNumber);



int main(void) {
	int	circularBuffer[SIZE_OF_BUFFER] = { 0 };	// Empty circular buffer
	int	optionNumber	=	0;	// User-input option number
	int	readIndex	    =	0;	// Index of the read pointer
	int	writeIndex	    =	0;	// Index of the write pointer
	int	bufferLength	=	0;	// Number of values in circular buffer
    int loopStatus      =   0;  // Loop condition variable

	while (loopStatus != EXIT_LOOP) {
		displayMainMenu();
		getNumber(&optionNumber);  // Get option number from user

	/* ---------------------------- OPTION 1 - WRITE --------------------------- */

		if (optionNumber == 1) {
    		// Check if buffer is full
			if (bufferLength == SIZE_OF_BUFFER) {
				printf("\n    Buffer is full!\n\n    ");
				getchar();
				continue;
			}

			printf("\n    Please input an integer to store in the array\n\n    ");
			getNumber(&circularBuffer[writeIndex]);	 // Write number to address of buffer index

			bufferLength++;	 //	Increase buffer size after writing
			writeIndex++;	 //	Increase writeIndex position to prepare for next write

			// If at last index in buffer, set writeIndex back to 0
			if (writeIndex == SIZE_OF_BUFFER) {
				writeIndex = 0;
			}
		}

	/* ---------------------------- OPTION 2 - READ ---------------------------- */

		else if (optionNumber == 2) {
            // Check if buffer is empty
			if (bufferLength == 0) {
				printf("\n    Buffer is empty!\n\n    ");
				getchar();
				continue;
			}

			printf("\n    The output value is %d\n\n    ", circularBuffer[readIndex]);
			getchar();

			bufferLength--;	 //	Decrease buffer size after reading
			readIndex++;	 //	Increase readIndex position to prepare for next read

            // If at last index in buffer, set readIndex back to 0
			if (readIndex == SIZE_OF_BUFFER) {
				readIndex = 0;
			}
		}

    /* ---------------------------- OPTION 3 - EXIT ---------------------------- */

        else if (optionNumber == 3) {
            printf("\n    Thanks for using the circular buffer!\n\n");
            loopStatus = EXIT_LOOP;
            continue;
        }        

	/* ----------------------------- INVALID OPTION ---------------------------- */

		else {
			printf("\n    Invalid option number!\n\n    ");
			getchar();
		}
	}
}



//  Function    :   displayMainMenu()
//  Description :   This function clears the screen and then displays the main menu
//                  for the program.
//  Parameters  :   N/A
//  Returns     :   N/A
void displayMainMenu(void) {
	printf("\n======================= CIRCULAR BUFFER ======================\n\n");
	printf("    Please choose from the following options:\n\n");
	printf("        1    Input  Value\n");
	printf("        2    Output Value\n");
	printf("        3    Exit Program\n");
	printf("\n==============================================================\n\n    ");
}



//  Function    :   getNumber()
//  Description :   This function gets a single integer as user input.
//  Parameters  :   int* pNumber: pointer to an int to store the number
//  Returns     :   int SUCCESS: if input was an int
//                  int FAILURE: if input was not an int
int getNumber(int* pNumber) {
	// An array of char to store the string
	char userInput[MAX_LENGTH_OF_STRING]	=	{ 0 };

	// Get user input
	fgets(userInput, MAX_LENGTH_OF_STRING, stdin);

	// Parse the user input for an integer and store it in the pNumber parameter
	if (sscanf(userInput, "%d", pNumber) != 1) {
		return FAILURE;
	}

	return SUCCESS;
}