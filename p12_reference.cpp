#include <iostream>

void addBonusByValue(int mark) { mark += 10; }          
void addBonusByReference(int& mark) { mark += 10; }  

void addBonusCapped(int& mark, int bonus) {
    mark += bonus;
    if (mark > 100) mark = 100;
}

void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int mark = 60;
    std::cout << "Start: " << mark << "\n";

    addBonusByValue(mark);
    std::cout << "After by-value:     " << mark << "  (unchanged: function got a copy)\n";

    addBonusByReference(mark);
    std::cout << "After by-reference: " << mark << "  (changed: function worked on the original)\n";

    addBonusCapped(mark, 50);
    std::cout << "After +50 capped:   " << mark << "\n";

    int a = 10, b = 20;
    std::cout << "\nBefore swap: a=" << a << ", b=" << b << "\n";
    swapValues(a, b);
    std::cout << "After swap:  a=" << a << ", b=" << b << "\n";
    return 0;
}
