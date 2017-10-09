/*
 ============================================================================
 Name        : FizzBuzzTest.c
 Author      : Victor Berzosa
 Version     : 1.0
 Copyright   : No copyright
 Description : Example code FizzBuzz
 ============================================================================
 */

/*==========================================================================
	Includes
 =========================================================================*/
#include <stdio.h>
#include <stdlib.h>

/*==========================================================================
	Definitions
 =========================================================================*/
#define MAX_NUMBER	25		// How many Fibonacci numbers do you want to check?
#define PRIME		0
#define NOT_PRIME	1

/*==========================================================================
	Variables
 =========================================================================*/


/*==========================================================================
	Function Declarations
 =========================================================================*/
int main(void);
void fizz_buzz(unsigned int number);
int check_prime	(unsigned int number);

/*==========================================================================
	Function Definitions
 =========================================================================*/



/**
 *  \fn int main(void)
 *  \brief Main loop for example
 */

int main(void)
{
	unsigned int a = 1;	// First Fibonacci number is 1
	unsigned int b = 0;
	unsigned int c = 0;
	unsigned int i = 0;

	for(i =0; i < MAX_NUMBER; i++)
	{

#ifdef TEST_MODE
		printf("Test Number %d \n", a);	// Pretty string to show what number is being tested
#endif

		fizz_buzz(a);

		c = b;
		b = a;

		a = b + c;

	}

	return EXIT_SUCCESS;
}





/**
 *  \fn void fizz_buzz(unsigned int number)
 *  \brief Function that prints different strings depending on the number introduced
 *  \param number the number that will be decisive in what text to print
 */
void fizz_buzz(unsigned int number)
{
	if ((number % 15) == 0)
	{
		puts("FizzBuzz");
	}
	else if (check_prime(number) == PRIME)
	{
		puts("BuzzFizz");
	}
	else if ((number % 3) == 0)
	{
		puts("Buzz");
	}
	else if ((number % 5) == 0)
	{
		puts("Fizz"); /* prints  */
	}
	else
	{
		printf("%d \n", number);
	}
}


/**
 *  \fn int check_prime	(int number)
 *  \brief Checks if the number is a prime number
 *  \param number The number to analyze
 *  \return Returns PRIME if its a prime, returns NOT_PRIME if it isn't.
 */
int check_prime	(unsigned int number)
{
	unsigned int div_numb = 2;			// Minimum prime divisor is 2

	int result_val = PRIME;

	if (number < 2)
	{
		result_val = NOT_PRIME;
	}
	else
	{

		for ( div_numb = 2 ; div_numb <= (number/2) ; div_numb++ )
		{
			if ( (number) % div_numb == 0 )
			{
				result_val = NOT_PRIME;
				break;
			}
		}
	}

	return result_val;
}
