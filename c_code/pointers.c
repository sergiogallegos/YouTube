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

// TODO: Calculate sum of array of elements using pointing arithmetic
// Do NOT use array indexing (arr[i]), only use pointers
int sum_array(int *arr, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += *(arr + i);
    }
    return result;
}

// TODO: Return pointer to the largest element in the array
int* find_max(int *arr, int size) {
    int *max = arr; // point to the first element
    for (int i = 1; i < size; i++) {
        if(*(arr + i) > *max) {
            max = arr + i; // move pointer
        }
    }
    return max;
}

// TODO: Reverse array using only pointers (no indexing)
// Use two pointers: one to start, one at end
void reverse_array(int *arr, int size) {
    int *left = arr;
    int *right = arr + size -1;
    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    printf("Before: ");
    print_array(arr, 5);
    reverse_array(arr, 5);
    printf("After: ");
    print_array(arr, 5); // Should print: 5 4 3 2 1

    int numbers2[] = {3, 7, 2, 9, 1};
    int *max_ptr = find_max(numbers2, 5);
    printf("Max value: %d\n", *max_ptr); // should print 9
    printf("Address: %p\n", (void*)max_ptr);

    int numbers[] = {1, 2, 3, 4, 5};
    int result = sum_array(numbers, 5);
    printf("Sum: %d\n", result); // Should print 15

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
