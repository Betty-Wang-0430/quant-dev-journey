#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <chrono>

int main() {

    const int N = 1'000'000;

    std::vector<int> vec;
    std::map<int, int> ordered;
    std::unordered_map<int, int> hashed;

    for (int i = 0; i < N; ++i) {
        vec.push_back(i);
        ordered[i] = i;
        hashed[i] = i;
    }

    std::cout << "Data structures created\n";
    std::cout << "Size: " << N << "\n";

    const int key = 999999;
    volatile long long result = 0;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000; ++i) {
        auto it = std::find(vec.begin(), vec.end(), key);
        if (it != vec.end()) {
            result += *it;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
        end - start
    );

    std::cout << "Vector: " << duration.count() << " us\n";

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000; ++i) {
        auto it = ordered.find(key);
        if (it != ordered.end()) {
            result += it->second;
        }
    }

    end = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(
        end - start
    );

    std::cout << "Map: " << duration.count() << " us\n";

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000; ++i) {
        auto it = hashed.find(key);
        if (it != hashed.end()) {
            result += it->second;
        }
    }

    end = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(
        end - start
    );

    std::cout << "Unordered map: " << duration.count() << " us\n";

    std::cout << "Result: " << result << "\n";

    return 0;
}