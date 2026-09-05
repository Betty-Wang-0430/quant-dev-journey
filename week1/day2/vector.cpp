#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10,20,30};
    vec.reserve(10); // reserve memory (at least) 
    /*
    vec.push_back(40);
    for(int v : vec) {
        std::cout << v << "\n";
    }
    std::cout << "size:" << vec.size() << "\n" // different from sizeof()
              << "capacity:" << vec.capacity() << "\n"; // increase capacity when running out of space 
    */
    std::cout << "first element:" << vec.at(0) << "\n"
              << "second element:" << vec.at(1) << "\n";
    vec.at(1) = 25; // can also use vec[1] = 25 if know index is valid
    vec.pop_back(); // changes size but often doesn't change the capacity
    std::cout << "final element:" << vec.back() << "\n";
    std::cout << "size: " << vec.size() << "\n"
          << "capacity: " << vec.capacity() << "\n";
    return 0;
}