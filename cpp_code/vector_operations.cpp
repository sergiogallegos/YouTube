#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 9};

    // Insert at position
    numbers.insert(numbers.begin() + 1, 100); // Insert 100 at index 2

    // Erase element at position
    numbers.erase(numbers.begin() + 1); // Remove element at index 1

    // Resize vector
    numbers.resize(10); // Grow to 10 elements (new ones are 0)
    numbers.resize(3);  // Shrink to 3 elements

    // Sorting
    std::sort(numbers.begin(), numbers.end()); // Sort ascending

    // Finding
    auto it = std::find(numbers.begin(), numbers.end(), 8);
    if (it != numbers.end()) {
        std::cout << "Found 8 at index: " << (it - numbers.begin()) << std::endl;
    }

    // Reversing
    std::reverse(numbers.begin(), numbers.end());
}
