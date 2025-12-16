#include <stdio.h>

void increment(int *num) {
    (*num)++; // Go to the address, increment the value there
}

// TODO: Write a function that swaps two integers using pointers
void swap(int *x, int*y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    //int x = 5;
    //increment(&x); // Pass address of x
    //printf("%d\n", x); // prints 6

    //int arr[5] = {10, 20, 30, 40, 50};
    //int *ptr = arr; // arr decays to pointer to first element

    //printf("%d\n", *ptr); // 10
    //printf("%d\n", *(ptr+1)); // 20
    //printf("%d\n", *(ptr+2)); // 30

    int a = 10;
    int b = 20;
    int *ptr;

    // TODO:
    // 1. Make ptr point to a
    ptr = &a;
    // 2. Print the value of a using ptr (should print 10)
    printf("%d\n", *ptr);
    // 3. Change the value of a to 50 using ptr
    *ptr = 50;
    // 4. Print a directly (should print 50)
    printf("%d\n", a);
    // 5. Make ptr point to b
    ptr = &b;
    // 6. Print the value of b usint ptr
    printf("%d\n", *ptr);

    printf("Before: a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("After: a=%d, b=%d\n", a, b);

    return 0;
}
