#include <stdio.h>

/**
 * Function to calculate the factorial of a number.
 *
 * @param n The non-negative integer for which to calculate the factorial.
 * @return The factorial of n, or -1 if n is negative.
 */
int factorial(int n)

	if (n < 0)

	return (-1);

	else if (n == 0)
{
	return (1);
}
else
{
	return (n * factorial(n - 1));
}

/**
 * Main function -  drive the factorial calculation and user interaction.
 */
int main(void)
{

int number;
	printf("Enter a non-negative integer: ");
	scanf("%d", &number);
int result = factorial(number);
	if (result == -1)
	printf("Factorial is not defined for negative numbers.\n");

else
printf("The factorial of %d is %d\n", number, result);

	return (0);
}
