#include <iostream>

int main() {
    int* p = new int(10);

    std::cout << *p << "\n";

    delete p;

    return 0;
}