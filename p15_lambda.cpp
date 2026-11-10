#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
    double marks[3];
    double average;
};

void show(const std::vector<Student>& v, size_t limit) {
    std::cout << std::fixed << std::setprecision(2);
    for (size_t i = 0; i < v.size() && i < limit; i++)
        std::cout << "  " << i + 1 << ". " << std::left << std::setw(10) << v[i].name
                  << " (ID " << v[i].id << ") avg " << v[i].average << "\n";
}

int main() {
    std::vector<Student> students = {
        {1, "Alice", {80, 75, 90}, 0},
        {2, "Brice", {45, 50, 40}, 0},
        {3, "Clarisse", {60, 65, 70}, 0},
        {4, "Daniel", {30, 55, 49}, 0},
        {5, "Estelle", {95, 88, 92}, 0},
        {6, "Franck", {60, 65, 70}, 0}, 
    };
    for (Student& s : students)
        s.average = (s.marks[0] + s.marks[1] + s.marks[2]) / 3.0;

    std::cout << "Original order:\n";
    show(students, students.size());

    std::stable_sort(students.begin(), students.end(),
                     [](const Student& a, const Student& b) { return a.average > b.average; });
    std::cout << "\nSorted by average (descending, ties keep original order):\n";
    show(students, students.size());

    double threshold = 50.0;
    auto passCount = std::count_if(students.begin(), students.end(),
                                   [threshold](const Student& s) { return s.average >= threshold; });

    std::cout << "\nTop 3:\n";
    show(students, 3);
    std::cout << "\nStudents with average >= " << threshold << ": " << passCount << "\n";
    return 0;
}
