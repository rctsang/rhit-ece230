#include <stdio.h>

/* TODO:
 * 
 * using only pointer arithmetic,
 * print the diagonal of the given square N x N matrix.
 * 
 * the matrix is stored as a flat array with each row of 
 * the matrix appearing consecutively after the previous.
 * 
 * e.g.
 * ```
 * int matrix[3 * 3] = {
 *     1, 2, 3,     // row 1
 *     4, 5, 6,     // row 2
 *     7, 8, 9      // row 3
 * };
 * 
 * print_diagonal(&matrix[0], 3);
 * // 1 5 9 
 * ```
 * 
 * you are allowed to use:
 * - ptr     a pointer to the start of the matrix
 * - N       the square matrix's dimension
 * 
 * and you may declare one loop variable with any initial value.
 */


int main(void) {
    const int N = 5;
    int matrix[N * N] = {
         1,  2,  3,  4,  5,
         6,  7,  8,  9, 10,
        11, 12, 13, 14, 15,
        16, 17, 18, 19, 20,
        21, 22, 23, 24, 25
    };

    int * ptr = &matrix[0];


    // YOUR CODE HERE
}