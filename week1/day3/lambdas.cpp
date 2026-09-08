#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // [capture](parameters){ code };
    auto square = [](int x) {
        return x * x;
    };
    std::cout << square(7);
    std::cout << "\n";

    std::vector<int> prices = {100, 105, 98, 110, 102};
    std::for_each(prices.begin(), prices.end(), [](int x) {
        if (x > 100) {
            std::cout << x << "\n";
        }
    });

    // count_if needs a lambda function that returns bool
    int count = std::count_if(prices.begin(), prices.end(), [](int x) {return x > 100;});
    std::cout << count << "\n";

    // max_element returns an iterator 
    auto it = std::max_element(prices.begin(), prices.end());
    // always remember to check if vector is empty 
    if (it != prices.end()) {
        std::cout << *it << "\n";
    }

    auto it1 = std::min_element(prices.begin(), prices.end());
    if (it1 != prices.end()) {
        std::cout << *it1 << "\n";
    }

    std::sort(prices.begin(), prices.end(), [](int a, int b) {
        // this means larger one is in the front of smaller one 
        return a > b;
    });

    // lower_bound() for binary search (ordered elements) O(log n)
    std::sort(prices.begin(), prices.end());
    auto it2 = std::lower_bound(prices.begin(), prices.end(), 103);
    if (it2 != prices.end()) {
        std::cout << *it2 << "\n";
    }

    auto isEven = [](int x) {
        return x % 2 == 0;
    };
    std::cout << isEven(10) << "\n";
    std::cout << isEven(7) << "\n";

    // performance 
    // vector O(n)   linear search
    // set O(log n)  oredered search / tree 
    // unordered_map O(1) in average   hash table 
    // reserve enough memory for the data 

    return 0;
}