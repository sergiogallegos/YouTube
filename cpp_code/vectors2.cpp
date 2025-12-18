#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50};

    // Method 1: Index-based (C-style)
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Method 2: Range-based for loop(C++11, preferred)
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Method 3: Range with reference
    for (int& num : numbers) {
        num *= 2; // Double each element
    }

    // Method 4: Iterators (more advanced)
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
