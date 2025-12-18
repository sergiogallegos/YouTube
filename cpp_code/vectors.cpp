#include <iostream>
#include <vector>

int main() {
    // 1. Creating vectors
    std::vector<int> v1;         // Empty vector
    std::vector<int> v2(5);      // 5 elements, initialized to 0
    std::vector<int> v3(5, 100); // 5 elements, all set to 100
    std::vector<int> v5 = {1, 2, 3, 4, 5}; // Initalized with values

    // 2. Adding elements
    std::vector<int> numbers;
    numbers.push_back(10);    // Add to end: [10]
    numbers.push_back(20);    // Add to end: [10, 20]
    numbers.push_back(30);    // Add to end: [10, 20, 30]

    // 3. Accesing elements
    std::cout << numbers[0] << std::endl;      // 10 (no bounds checking)
    std::cout << numbers.at(1) << std::endl;   // 20 (with bounds checking)
    std::cout << numbers.front() << std::endl; // 10 (first element)
    std::cout << numbers.back() << std::endl;  // 30 (last element)

    // 4. Size and capacity
    std::cout << "Size: " << numbers.size() << std::endl;        // 3
    std::cout << "Capacity: " << numbers.capacity() << std::endl; // =3
    std::cout << "Empty? " << numbers.empty() << std::endl; // false

    // 5. Removing elements
    numbers.pop_back();    // Remove last: [10, 20]
    numbers.clear();       // Remove all: []


    // C array - fixe size
    int c_array[5] = {1, 2, 3, 4, 5};
    // c_array[10] = 100; // Undefined behavior! No bounds checking
    // Can't grow or shrink
    // Need to pass size separately to functions

    // C++ vector - dynamic size
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6); // Can grow dynamically
    vec.pop_back();  // Can shrink dynamically
    vec.size();    // Size is known
    // vec[10] = 100; // Throws an exception (out_of_range)

    return 0;
}
