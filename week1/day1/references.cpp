#include <iostream>

int main() {
int x = 10;
// r is another name of x, can change x through r
int& r = x;
r = 20;

std::cout << x << "\n";
std::cout << r << "\n";

int *p = &x;
*p = 30;

std::cout << x << "\n";
std::cout << r << "\n";
std::cout << *p << "\n";

return 0;
}

// with keyword const
// const int& r = x
// cannot change r