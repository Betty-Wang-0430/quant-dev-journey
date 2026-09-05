#include <array>
#include <iostream>

int main() {
    std::array<int, 5> prices = {10, 20, 30, 40, 50};
    for (int p : prices) {
        std::cout << p << "\n";
    }
    std::cout << prices.size() << "\n";
    prices.at(2) = 35;
    for (int p : prices) {
        std::cout << p << "\n";
    }
    return 0;
}