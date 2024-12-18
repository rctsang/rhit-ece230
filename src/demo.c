#include <stdio.h>


const int LARGEST_DIVISOR = 10;


int largest_remainder(int value);
int divide_values(int dividend, int divisor);


int largest_remainder(int value)
{
    int max = 0;
    for (int divisor = 1; divisor <= LARGEST_DIVISOR; divisor++) {
        int quotient = divide_values(value, divisor);
        int remainder = value - quotient * divisor;
        if (remainder > max) {
            max = remainder;
        }
    }
    return max;
}


int divide_values(int dividend, int divisor)
{
    return dividend / divisor;
}


int main(void)
{
    printf("LARGEST_DIVISOR: %d\n", LARGEST_DIVISOR);
    printf("divide_values(15, 7) = %d\n", divide_values(15, 7));
    printf("largest_remainder(32) = %d\n", largest_remainder(32));

    // parameters in function calls can be any valid expression,
    // even other function calls.

    int var = 12;
    printf("%d\n", largest_remainder(divide_values(6 * 8, divide_values(5 * 3, var))))
}