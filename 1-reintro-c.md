---
title: Reintroduction to C
date: 10-02-2023
---

# Reintroduction to C

## Programming Paradigms

Approaches to solving problems.

### Imperative Programming (C, C++, Java)
* Defining instruction step-by-step
* HOW to solve a problem

#### Procedural Programming
* Based on procedures (subroutines)
* Uses procedures to break down large pieces of code/logic:
    * Inputs as arguments
    * Outputs as return values
* You can use other people's procedures (via libraries)

#### Object-oriented Programming
* Based on objects that contain both data and code.
* Code are procedures (or methods)  

### Declarative Programming (Haskell)
* WHAT to do to solve the program.

### Which is the best paradigm?
* Procedural:
    * Simple/Straightforward
    * Potentially easier to performance-optimize
    * Can become prohibitive with large codebases
* OOP:
    * Large projects with lots of developers
    * Modularity -> maintainability and code reuse

### Best programming language?
There is none!
Each language is designed around a goal, you should consider which 
one suits your preferences and problem.

## Types in C
It is to note that these types are not standardized (as in they can be different sizes)
which can lead to undefined behavior (UB) when compiling for portable systems.


```c title="Common types in C."
// Commonly 1 byte
char a;

// Commonly 2 bytes
short b;

// Commonly 4 bytes
int c;

// Commonly 8 bytes
long d;

// Single-precision floating point 4 bytes by IEEE 754 standard
float e;

// Doubke-precision floating point 8 bytes by IEEE 754 standard
double f;

// 16 bytes floating point precision -- Not always supported.
long double g;

// No sign bit!
unsigned int h;
```

### `char`
These are integers!
The syntax for characters is single quotes: `'A'` is the integer used 
to represent `A` in ASCII.

### `float` and `double`
C defaults to `doubles` when you write decimals (aka `1.1234` is a double),
for single-precision append `f` to the end of the decimal: `1.23f`.

Sometimes the compiler will convert single- to double-precision or vice-versa since some architectures
do not support operations on either.

### Booleans
C doesn't come with booleans out-of-the-box,
here the integers `0` and `1` moonlight as `false` and `true`.

`if` statements treat any non-0 value as `true`.

### Arrays
C Arrays are just collections of values stored contiguously in memory.

### `struct`s
Makes a new type with the name `struct X` which can be used to group
values together.

The dot operator (`.`) is used to access internal members of the struct [EX 1].
The arrow operator (`->`) is used to access internal members of a struct via the struct's pointer [EX 2].


```c title="Struct Example: Coordinates"
struct Coordinate {
    int x;
    int y;
    int z;
}

int main(void) {
    // Make a new coordinate (P1)
    struct Coordinate t = struct Coordinate {
        .x  = 2,
        .y  = 3,
        .z  = 4
    };

    // [EX 1]
    struct Coordinate d2;
    d2.x = 2;

    // [EX 2]
    struct Coordinate* d2_ptr = &d2;
    d2_ptr->x = 2;
}
```