#include <iostream>
#include <vector>
#include <chrono>
#include <random>

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

int main() {
    const int N = 10'000'000;

    std::vector<int> v(N, 1);
    std::vector<int> indices(N);

    // Create indices 0, 1, 2, ..., N-1
    for (int i = 0; i < N; ++i) {
        indices[i] = i;
    }

    // Shuffle indices for random access
    std::mt19937 rng(42);
    std::shuffle(indices.begin(), indices.end(), rng);

    long long sum = 0;

    // --------------------------------
    // Sequential access
    // --------------------------------

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        sum += v[i];
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto sequential_time =
        std::chrono::duration_cast<std::chrono::microseconds>(
            end - start
        ).count();

    std::cout << "Sequential: " << sequential_time << " us\n";


    // --------------------------------
    // Random access
    // --------------------------------

    sum = 0;

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        sum += v[indices[i]];
    }

    end = std::chrono::high_resolution_clock::now();

    auto random_time =
        std::chrono::duration_cast<std::chrono::microseconds>(
            end - start
        ).count();

    std::cout << "Random: " << random_time << " us\n";
    std::cout << "Sum: " << sum << "\n";


    // --------------------------------
    // Vector without reserve
    // --------------------------------

    std::vector<int> no_reserve;

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        no_reserve.push_back(i);
    }

    end = std::chrono::high_resolution_clock::now();

    auto no_reserve_time =
        std::chrono::duration_cast<std::chrono::microseconds>(
            end - start
        ).count();

    std::cout << "Without reserve: "
              << no_reserve_time << " us\n";


    // --------------------------------
    // Vector with reserve
    // --------------------------------

    std::vector<int> with_reserve;
    with_reserve.reserve(N);

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        with_reserve.push_back(i);
    }

    end = std::chrono::high_resolution_clock::now();

    auto with_reserve_time =
        std::chrono::duration_cast<std::chrono::microseconds>(
            end - start
        ).count();

    std::cout << "With reserve: "
              << with_reserve_time << " us\n";

    std::vector<int> vec;

    for (int i = 0; i < 20; ++i) {
        vec.push_back(i);

        std::cout << "Size: " << vec.size()
                  << ", Capacity: " << vec.capacity() << "\n";
    }
}


// push_back()  when already has an object 
// emplace_back()  constructs the object directly in the vector 
// orders.push_back(std::move(order))  allow the existing object to be moved rather than copied

