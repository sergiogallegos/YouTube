// main.cpp
// This programm will be made on C++20 Modern C++ Programming
// This is a sample program to demonstrate the use of C++20 features
// Modern Mixed-Style
// procedural for performance, template/generic for abstraction
// RAII for resource management, functional patterns for clarity
// minimal OOP (composition>inheritance)

// Data Processor
// Goal: Read numbers from a file, filter them, compute statistics and
// sort results.


#include <algorithm>
#include <concepts>
#include <fstream>
#include <iostream>
#include <memory>
#include <numeric>
#include <optional>
#include <ranges>
#include <string>
#include <vector>

// -------------------------------
// 1. Generic numeric constraint
// -------------------------------
template <typename T>
concept Number = std::integral<T> || std::floating_point<T>;

// -------------------------------
// 2. RAII File Reader (OOP + RAII)
// -------------------------------
class FileReader {
public:
    explicit FileReader(const std::string& path) {
        file_ = std::make_unique<std::ifstream>(path);
        if (!file_->is_open()) {
            throw std::runtime_error("Cannot open file: " + path);
        }
    }

    std::vector<double> read_numbers() {
        std::vector<double> data;
        double value;
        while (*file_ >> value) {
            data.push_back(value);
        }
        return data;
    }

private:
    std::unique_ptr<std::ifstream> file_;  // RAII
};

// -------------------------------
// 3. Statistics Calculator (Procedural + Generic)
// -------------------------------
template <Number T>
struct Stats {
    T min;
    T max;
    double avg;
};

template <Number T>
std::optional<Stats<T>> compute_stats(const std::vector<T>& data) {
    if (data.empty())
        return std::nullopt;

    auto [mn, mx] = std::minmax_element(data.begin(), data.end());
    double avg = std::accumulate(data.begin(), data.end(), 0.0) / data.size();

    return Stats<T>{ *mn, *mx, avg };
}

// -------------------------------
// 4. Main App (Ranges + Lambdas)
// -------------------------------
int main() {
    try {
        FileReader reader("numbers.txt");
        auto nums = reader.read_numbers();

        auto view = nums | std::views::filter([](double x) { return x > 0.0; });
        std::vector<double> filtered(view.begin(), view.end());

        auto result = compute_stats(filtered);

        if (!result) {
            std::cout << "No valid data.\n";
            return 0;
        }

        // Structured bindings (C++17+)
        auto [mn, mx, avg] = *result;

        std::cout << "Stats:\n";
        std::cout << "  Min: " << mn << "\n";
        std::cout << "  Max: " << mx << "\n";
        std::cout << "  Avg: " << avg << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
