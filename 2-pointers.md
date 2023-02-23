---
title:  Pointer in C
date:   2023-02-17
---

# Pointers in C

## Referencing with `&`
The `&` operator in C gives the address that the variable
is in memory.

**Note**: You can use the `%p` format specifier to make C
format the address as hexadecimal: `0x89a8b8d76a8`.


```c
#include <stdio.h>
int main(void) {
    int n = 10;
    printf("n = %%d; &n = %p", n, &n);
    return 0;
} 

```
## Pointers are types, too!
In C, pointers point to a specific type.
They can be explicitly declared with syntax `int* var`, `int * p`, `int *p`:
```c
// Two integer pointers.
int *p, *q;

// Integer pointer p, and integer q.
int* p, q;
```

## Dereferencing with `*`
The `*` operator can also obtain the value of the memory address, as well as modify it.

```c
int n = 10;

// Pointer to n
int* p = &n;

// Reading the value at pointer p   \/ 
printf("Address: %p; Value: %d", p, *p); // Address: 0x________; Value: 10

// Set the value of n to 20.
*p = 20;

printf("Address: %p; Value: %d", p, *p); // Address: 0x________; Value: 20

```

## Arithmetic with pointers
Since pointers are just integers, we can do maths with them &mdash; though you really shouldn't!
```c
int n  = 10;
int* p = &n;

printf("Address: %p; Value: %d", p, *p); // Address: $1; Value: 10
p = p + 1;  // NOTICE: This DOES NOT (always) increment the address by one,
            //         it increments it by the size of the type the pointer refers to.
            //         In this case the new p is actually p + 4 `sizeof(int).

printf("Address: %p; Value: %d", p, *p); // Address: $1 + 4; Value: 10
```

## Passing-by-value and -by-reference
### Pass-by-value
When arguments are provided to a function, a copy of them is made.
This means the function cannot change its parameters.

### Pass-by-reference
*Technically* in C, there is no such thing as passing by reference; everything is passed by value.

Though with pointers, we can emulate the behavior of pass-by-reference:

```c
#include <stdio.h>


void increment(int* ptr_n) {
    (*ptr_n)++;
}

int main(void) {
    int n = 10;
    
    printf("n == %d\n", n); // n == 10 
    
    int* ptr_n = &n;

    // Alternatively use "increment(&n)";
    increment(ptr_n); // Copies the int*, which can still be dereferenced to n.

    printf("n == %d\n", n); // n == 11 
}
```

## Pointers in Java ??
Java does not explicitly give memory access, but it has the same ideas.

In Java, there are two classes of types:
* Primitives &mdash; `int`, `char`, `double`
* Non-Primitives &mdash; Objects (`Integer`, `Double`), literally anything else.

Primitives are passed by value, whereas non-primitives are passed by reference:

```java
public class A {
    private String name;

    void setName(String name) {
        this.name = name;
    }

    void printName() {
        System.out.println(this.name);
    }
}

public class Main {
    public static void main(String[] args) {
        A objA = new A();
        B objB = objA;

        a.setName("Bob");

        a.printName(); // Bob
        b.printName(); // Bob

        b.setName("Jeff");

        // What ?!
        a.printName(); // Jeff
        a.printName(); // Jeff
    }
}
```

Interestingly, arrays are also passed-by-reference, even for arrays of
primitive types.

## Arrays as Pointers
In C, arrays are really just pointers: they point to the first (0th) index
of the array.

`a[i]` is shorthand for `*(a+1)`

Though, one difference: array pointers are constant.

## Pointers with no type `*void`
Void pointers are used to reference any data type &mdash; this makes it
able to reference an `int` as `char[4]`.

Note: when you increment a `void*`, it only increments by one byte instead of any other size.

```c
#include <string.h>

int main(void) {
    int a;

    // Casting int* -> void*, then void* -> char*
    char* bytes_of_a = (char*)(void*)&a;
}
```

## Linked Lists 
Linked lists are a collection of list nodes, which each contain a value, and a pointer to the next node.

If the node is at the end of the list, it has a **NULL** Pointer `(void*)0`.
Null pointers are usually used as error conditions, or as N/A.

You MUST ensure you can handle this case.

```c
struct LinkedNode {
    int value;
    struct LinkedNode* next;
}
```

## File Handling / IO

In C, there is a special opaque type for files, `FILE`. It's opaque, as in we cannot touch the type directly, only by using functions with its pointer.

### File-handling Functions
* `fopen` &mdash; opens a file.
* `fclode` &mdash; closes a file and ensures that no-one else is using it.
* `fread` &mdash; reads a number of bytes from a file into a buffer.
* `fwrite` &mdash; writes a number of bytes to a file.

```c
/// Read from test1.txt and copy it into test2.txt
int main(void)
{
    FILE *input, *output;
    char buf[1204]; // Temporary buffer of 1024 bytes/

    int nread; // Number of bytes read.

    input = fopen("test1.txt", "r");
    output = fopen("test2.txt", "w");

    if (input == NULL || output == NULL) {
        return 1;
    }

    do {
        nread = fread(buff, 1, 1024, inp); // Read up to 1024 bytes into buf, return the number of bytes read.
        fwrite(buff, 1, nread, out); // Write the buffer back to the file.
    } while(nread > 0); // Keep reading until we run out of bytes 

    fclose(input);
    fclose(output);

    return 0;
}
```

### Other I/O
`<stdio.h>` sets up the standard three file pointers:
* STDOUT &mdash; standard output; used for normal printing to the console.
* STDIN  &mdash; standard input; used to gather input from the console.
* STDERR &mdash; standard error; used to write errors to console (doesn't clog up STDOUT)

Essentially, by calling `printf`, we're actually calling `fprintf`

## Function Pointers
We can also get dynamic access to functions, by using their pointers.

Here, we can make a function `for_each` that executes a function for each element.
```c title="For-each example"
void for_each(int* arr, size_t size, void (func*)(int)) {
    for (size_t i = 0; i < size; i++>) {
        func(arr[i]);
    }
}

int bigBoiArray[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

void logIt(int i) {
    printf("%d\n", i);
} 

int main(void) {
    for_each(bigBoiArray, 8, logIt);
}
```