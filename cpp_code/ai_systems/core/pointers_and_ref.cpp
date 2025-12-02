#include <iostream>
#include <vector>
#include <memory>

/*
 * Increment
 * Function that takes an integer by reference (&)
 * and increments it by 1.
 */
void increment(int& x) {
    x++;
}

/*
 * Allocate
 * Function that allocates a block of 1000 floats
 * on the heap using new.
 */
void allocate_float(float*& x) {
    x = new float[1000];
}

/*
 * Pass by Reference
 * Function that takes a Vector of floats by reference (&)
 * and calculates the sum of all elements.
 */
void calculate_sum(const std::vector<float>& vec, float& sum) {
    sum = 0;
    for (float f : vec) {
        sum += f;
    }
}

/*
 * RAII Test
 * Modify the allocation to use std::unique_ptr<float[]> instead
 * of a raw pointer. Verify that you not longer need to explicitly
 * call delete[] - the memory cleans up automatically.
 */
void allocate_float_2(std::unique_ptr<float[]>& x) {
    x = std::make_unique<float[]>(1000);
}

int main() {
    int a = 10;
    int* p = &a;

    std::cout << "Value: " << a << "\n";
    std::cout << "Pointer points to: " << *p << "\n";

    increment(a);
    std::cout << "After increment: " << a << "\n";

    // test allocate_float(float*& x)
    float* x = nullptr;
    allocate_float(x);
    std::cout << "Allocated memory: " << x << "\n";
    delete[] x;

    // test allocate_float_2(std::unique_ptr<float[]>& x)
    std::unique_ptr<float[]> y;
    allocate_float_2(y);
    std::cout << "Allocated memory: " << y.get() << "\n";

    // test calculate_sum(const std::vector<float>& vec, float& sum)
    std::vector<float> vec = {1.0f, 2.0f, 3.0f};
    float sum = 0.0f;
    calculate_sum(vec, sum);
    std::cout << "Sum: " << sum << "\n";
}
