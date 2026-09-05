#include <set>
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    /*
    // set is ordered 
    std::set<int> prices;
    prices.insert(100);
    prices.insert(101);
    // set don't have repeated value
    prices.insert(100);
    prices.insert(99);
    for (const auto& p : prices) {
        std::cout << p << "\n";
    }
    if (prices.contains(100)) {
        std::cout << "100 exists\n";
    }
    */
    std::set<int> prices = {100, 101, 99, 102};
    auto it = prices.begin(); // it is an iterator 
    std::cout << *it << "\n"; // gets the value 
    ++it; // moves to the next element
    std::cout << *it << "\n";
    it = prices.begin();
    // end is after the last element 
    while (it != prices.end()) {
        std::cout << *it << "\n";
        ++it;
    }
    /*
    for (auto it = prices.begin(); it != prices.end(); ++it) {
        const auto& p = *it;
        std::cout << p << "\n";
    }   
    */
    /*
    auto it = prices.find(101); 
    if (it != prices.end()) {
        std::cout << "Found: " << *it << "\n";
    } else {
        std::cout << "Not found\n";
    }
    */
    /*
    auto it = prices.lower_bound(101) finds the first element greater or equal to 101
    if (it != prices.end()) {
        std::cout << "First price >= 101: " << *it << "\n";
    }
    */
    std::vector<int> numbers = {20, 30, 10};
    std::sort(numbers.begin(), numbers.end());
    for (int n : numbers) {
        std::cout << n << "\n";
    }
    return 0;
}
