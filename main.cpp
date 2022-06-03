#include <iostream>
#include "Cube.h"

int main() {
    Cube cb;
    cb.print();
    std::cout << "---------------------
";
    cb.random_rotates(7);
    cb.print();
    std::cout << "---------------------
";
    cb.solution();
    cb.print();
    std::cout << "---------------------
";
    cb.print();
    cb.random_rotates(67);
    std::cout << "---------------------
";
    cb.print();
    cb.solution();
    std::cout << "---------------------
";
    cb.print();
    return 0;
}
