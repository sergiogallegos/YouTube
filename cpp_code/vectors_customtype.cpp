#include <iostream>
#include <vector>
#include <string>

struct Sensor {
    std::string name;
    int reading;
    bool active;
};

int main() {
    // Vector of struct
    std::vector<Sensor> sensors;

    Sensor s1 = {"Temperature", 25, true};
    Sensor s2 = {"Pressure", 100, false};

    sensors.push_back(s1);
    sensors.push_back(s2);

    // Access members
    for (const Sensor& s : sensors) {
        std::cout << s.name << ": " << s.reading << std::endl;
    }

    // Vector of strings
    std::vector<std::string> names = {"Sergio", "Robot", "PLC"};
    names.push_back("Camera");

    // 2D vector: 3 rows, 4 columns
    std::vector<std::vector<int>> matrix(3, std::vector<int>(4, 0));

    // Set values
    matrix[0][0] = 1;
    matrix[1][2] = 5;

    // Iterate 2D vector
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Jagged array (rows can have different lengths)
    std::vector<std::vector<int>> jagged;
    jagged.push_back({1, 2, 3});
    jagged.push_back({4, 5});
    jagged.push_back({6, 7, 8, 9});

    return 0;
}
