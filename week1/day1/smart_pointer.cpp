#include <iostream>
#include <memory>

int main() {
    //std::unique_ptr<int> p = std::make_unique<int>(10);

    // unique pointer will automatically clean up when the function ends 
    auto p = std::make_unique<int>(10); // p owns an int 

    *p = 20; // still behaves like normal pointer 

    std::cout << *p << "\n";

    // unique means only one owner of this object
    // so auto q = p is false 
    // now p is a null pointer 
    auto q = std::move(p);

    std::cout << *q << "\n";

    return 0;
}