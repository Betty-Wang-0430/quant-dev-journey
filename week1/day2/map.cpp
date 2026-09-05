#include <map>
#include <iostream>

int main() {
    std::map<int, int> orders;
    orders[100] = 50;
    orders[101] = 20;
    orders[102] = 80;
    // auto means automatically figure out order is a map
    // & means use the original data not the copy so cheaper 
    // const do not allow modify
    for(const auto& order : orders) {  
        std::cout << order.first << "->"<< order.second << "\n"; 
    }
    return 0;
}