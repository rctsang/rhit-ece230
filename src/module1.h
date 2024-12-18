
/**
 * this is called a "header guard".
 * it prevents this header file from being included multiple times
 * during compilation, which could otherwise give you compiler errors.
 * 
 * header files generally contain `extern` definitions of global variables,
 * function prototypes, macros, or any other constructs that are meant
 * to be visible to other files using the module
 */
#ifndef __FILE1_H__
#define __FILE1_H__

/**
 * we can put the prototypes for our functions in `file1.c` here
 * instead of in `file1.c`.
 * 
 * note that the function definition is not here, but in `file1.c`.
 */

// we create `extern` declarations of any publicly
// visible global variables we created in the definition of our module
// so that they are available in other files.
extern const int LARGEST_DIVISOR;

/**
 * @brief      computes the remainder of the given value divided by numbers
 *             1 to 10 and returns the largest remainder.
 *
 * @param[in]  value  The value
 *
 * @return     largest computed remainder
 */
int largest_remainder(int value);

/**
 * @brief      floor divide the dividend by the divisor
 *
 * @param[in]  dividend  The dividend
 * @param[in]  divisor   The divisor
 *
 * @return     result
 */
int divide_values(int dividend, int divisor);



#endif