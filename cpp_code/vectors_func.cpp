#include <iostream>
#include <vector>

// Pass by value (copies entire vector - expensive!
void printVector1(std::vector<int> vec) {
    for (int num: vec) {
        std::cout << num << " ";
    }
}

// Pass by const reference (no copy, can't modify - preferred fo reading)
void printVector2(const std::vector<int>& vec) {
    for (int num: vec) {
        std::cout << num << " ";
    }
}

// Pass by reference (no copy, can modify)
void doubleValues(std::vector<int>& vec) {
    for (int& num : vec) {
        num *= 2;
    }
}
