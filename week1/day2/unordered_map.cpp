#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, int> orders;
    orders[100] = 50;
    orders[101] = 20;
    orders[102] = 80;
    std::cout << orders[101] << "\n";
    orders[101] = 35;
    std::cout << orders[101] << "\n";
    for(const auto& order : orders) {  
        std::cout << order.first << "->"<< order.second << "\n"; 
    }
    return 0;
}