# Pointers

## Learning Objectives

After this lesson, students should be able to:
- Determine how data stored in a computer is modified using operations involving **C pointers**
- Use **reference** and **dereference** operators to update the value of a variable using pointers

## Basics

A **memory address** is an integer value that represents the location of a single byte in memory.

The **reference operator `&`** is used to obtain a variable's address.

A **pointer** is a variable type that contains a memory address.

The **dereference operator `*`** can be used to indirectly access or modify a the value stored at an address.

> Note: the reference and dereference operators have **no space** separating them from their operand.
> e.g. `&variable`, not `& variable` and `*pointer`, not `* pointer`.
> 
> This is generally to avoid confusion created by the binary forms of these operators (bitwise "and"
> and multiplication)

**Example 1**
```c
int32_t var = 42; // declare and assign a variable `var`
int32_t * ptr;    // declare a pointer `ptr` of type (int32_t *)
ptr = &var;       // assign the address of variable `var` to `ptr`

var = 75;

printf("*ptr=%d\n", *ptr); // prints ???
*ptr += var;

printf("*ptr=%d\n", *ptr); // prints ???
```

**Example 2**
```c
int32_t var = 42; // declare and assign a variable `var`
int32_t * ptr;    // declare a pointer `ptr` of type (int32_t *)
ptr = &var;       // assign the address of variable `var` to `ptr`

int16_t * ptr2; // define `ptr2` of type (int16_t *)
ptr2 = ptr;     // assign value of `ptr` to `ptr2`
var = 0xbadc0de;

printf("%x\n", *ptr2); // prints ???
```

## Pointer Arithmetic

Pointers can have **integer values added to** and **subtracted from** them.
These are the only binary arithmetic operations allowed in pointer arithmetic (i.e. `*`, `/`, `%`, `|`, `&`, `^` are not allowed).
You also cannot add or subtract pointers to or from other pointers.

When adding an integer to a pointer, the amount that the address stored in the pointer changes by is determined by the size (in bytes) of the type that the pointer points to.
So adding 1 to a `char` pointer would increment the stored address by 1, a `short` pointer would increment by 2, and an `int` pointer by 4.

E.g.
```c
char char_var = 0; // char is 1 byte
char * char_ptr = &char_var; // say &char_var is 0x20040000
char_ptr++; // char_ptr now stores address 0x20040001.

int int_var = 0; // int is 4 bytes
int * int_ptr = &int_var; // if &int_var is 0x20040004
int_ptr++; // int_ptr now stores address 0x20040008
```

**Example 3**
```c
uint32_t * base_address = (uint32_t *) 0x20004000u;
uint32_t * ptr = base_address;
uint32_t i = 10;
ptr++;          // ok
ptr += i;       // ok
printf("%x\n", (uint32_t) ptr); // prints ???

uint32_t * ptr2 = base_address + 10;        // ok

printf("%x\n", (uint32_t) (ptr2 + ptr));    // compiler error
printf("%x\n", (uint32_t) (ptr2 - ptr));    // compiler error
printf("%x\n", (uint32_t) (ptr2 % ptr));    // compiler error
printf("%x\n", (uint32_t) (ptr2 | ptr));    // compiler error
printf("%x\n", (uint32_t) (ptr2 & ptr));    // compiler error
printf("%x\n", (uint32_t) (ptr2 ^ ptr));    // compiler error
```

**Example 4**
```c
int32_t arr[] = { 0, 1, 1, 2, 3, 5, 8, 13 };

int32_t * ptr = &arr[0]; // address of first element in `arr`

printf("%d\n", *(ptr + 2)); // prints ???
printf("%d\n", *(ptr + 5)); // prints ???
printf("%d\n", *(ptr + 8)); // prints ???
```

## Exercise 1

Write a program that prints out the diagonal of a 2D square matrix stored as a single array.

The files for Exercise 1 are located in [this repository](https://github.com/rctsang/rhit-ece230) at `exercise1`.

Download the files and follow along in your code editor.

## Pointer Pitfalls

There are many ways to shoot yourself in the foot with pointers.

Some of the most common are:
1. Uninitialized pointers - forgetting to initialize a pointer.
```c
int * dangling_ptr;
*dangling_ptr = 17; // undefined behavior
```
2. Invalid pointers - assigning an unintended value to a pointer
```c
int * invalid_ptr = 42; // sometimes a compiler error
*invlid_ptr = 5; // undefined behavior
```
3. Null pointer dereference - dereferencing a null pointer (a pointer to address 0)
```c
int * null_ptr = NULL; // `NULL` = 0
int val = *null_ptr; // undefined behavior
```

These all generally result in "undefined behavior" (e.g. a segmentation fault) and in the worst case can be explioted by an attacker.

A good question to ask yourself regularly when work with pointers is: "Where does the pointer point to?"
