#include <iostream>
#include <vector>
#include <algorithm>

int lower_bound_custom(const std::vector<int>& prices, int target) {
    int left = 0;
    int right = prices.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (prices[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    std::vector<int> prices = {
        101, 105, 99, 110, 103
    };

    std::sort(prices.begin(), prices.end());

    for (int price : prices) {
        std::cout << price << " ";
    }

    std::cout << "\n";

    auto it = std::lower_bound(prices.begin(), prices.end(), 104);

    if (it != prices.end()) {
        std::cout << *it << "\n";
    }

    std::cout << lower_bound_custom(prices, 104) << "\n";
    std::cout << lower_bound_custom(prices, 103) << "\n"; 
    std::cout << lower_bound_custom(prices, 120) << "\n"; 

    return 0;
}