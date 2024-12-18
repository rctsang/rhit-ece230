#include "module1.h"

/**
 * the #include macro copies all the contents of the `module1.h` file
 * verbatim into this one, so we need not declare function prototypes
 * here.
 */

// global variable
// accessible from anywhere, including other c files
const int LARGEST_DIVISOR = 10;

// private global variable
// accessible from anywhere inside this file, but invisible to other files
static int PRIVATE;


/**
 * the `module.c` file should provide definitions for all the function
 * prototypes declared in its corresponding header file
 */


int largest_remainder(int value) {
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


/** 
 * notice that `largest_remainder` calls `divide_values`,
 * but `divide_values` is defined after.
 * 
 * this is allowed because the prototypes have already been declared,
 * so the compiler knows that `divide_values` exists before it 
 * reaches the first usage of it.
 * 
 * as long as it has encountered the prototype, the compiler will
 * trust that the function is defined somewhere else and that 
 * everything will be resolved by runtime.
 */

int divide_values(int dividend, int divisor) {
    return dividend / divisor;
}
