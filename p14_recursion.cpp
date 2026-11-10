#include <iostream>
#include <limits>
#include <string>

unsigned long long factorial(int n, int depth = 0) {
    std::string indent(depth * 2, ' ');
    std::cout << indent << "factorial(" << n << ") called\n";
    unsigned long long result;
    if (n == 0 || n == 1) {
        result = 1;
    } else {
        result = n * factorial(n - 1, depth + 1);
    }
    std::cout << indent << "factorial(" << n << ") returns " << result << "\n";
    return result;
}

int recursiveSum(int n) {
    if (n <= 0) return 0;
    return n + recursiveSum(n - 1);
}

unsigned long long factorialIter(int n) {
    unsigned long long r = 1;
    for (int i = 2; i <= n; i++) r *= i;
    return r;
}
int sumIter(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) s += i;
    return s;
}

int main() {
    int n;
    std::cout << "Enter n (0-20) for factorial: ";
    while (!(std::cin >> n) || n < 0 || n > 20) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid. Enter a number from 0 to 20: ";
    }

    std::cout << "\nTrace:\n";
    unsigned long long f = factorial(n);
    std::cout << "\nRecursive factorial(" << n << ") = " << f << "\n";
    std::cout << "Iterative factorial(" << n << ") = " << factorialIter(n) << "\n";

    int m;
    std::cout << "\nEnter m for sum 1..m: ";
    while (!(std::cin >> m) || m < 0 || m > 10000) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid. Enter 0 to 10000: ";
    }
    std::cout << "recursiveSum(" << m << ") = " << recursiveSum(m) << "\n";
    std::cout << "sumIter(" << m << ")      = " << sumIter(m) << "\n";
    return 0;
}
