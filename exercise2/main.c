#include <stdio.h>

/* TODO:
 * 
 * write a function named `reverse` that takes 2 parameters,
 * 1. a pointer to the start of an array
 * 2. the array size
 * 
 * the function should reverse the elements of the list
 * in-place.
 * 
 * !!! you may not create a new array !!!
 */

// YOUR CODE HERE


// DO NOT MODIFY MAIN
int main(void)
{
    const int N = 25;
    int array[N] = {
         1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
        16, 17, 18, 19, 20, 21, 22, 23, 24, 25
    };

    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    // should print:
    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

    // call reverse
    reverse(&array[0], N);

    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    // should print:
    // 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
}