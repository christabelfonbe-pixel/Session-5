#include <iostream>
#include <limits>
#include <vector>

int main() {
    int score = 75;
    int* pointer = &score;

    std::cout << "score     = " << score << "\n";
    std::cout << "&score    = " << &score << "\n";
    std::cout << "pointer   = " << pointer << "\n";
    std::cout << "*pointer  = " << *pointer << "\n";

    *pointer = 90;
    std::cout << "\nAfter *pointer = 90:\n";
    std::cout << "score = " << score << ", *pointer = " << *pointer << "\n";

    int n = 0;
    std::cout << "\nHow many values (1-1000)? ";
    if (!(std::cin >> n) || n < 1 || n > 1000) {
        std::cout << "Invalid size.\n";
        return 1;
    }

    int* arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = (i + 1) * 10;
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    delete[] arr;
    arr = nullptr;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = (i + 1) * 10;
    std::cout << "Vector size: " << v.size() << " (freed automatically)\n";

    return 0;
}
