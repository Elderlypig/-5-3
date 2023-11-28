#include <iostream>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    int score;

    Student(std::string name, int score) {
        this->name = name;
        this->score = score;
    }
};

int partition(std::vector<Student>& students, int low, int high);

// Реализация сортировки QuickSort
void quickSort(std::vector<Student>& students, int low, int high) {
    if (low < high) {
        int pivot = partition(students, low, high);
        quickSort(students, low, pivot - 1);
        quickSort(students, pivot + 1, high);
    }
}

int partition(std::vector<Student>& students, int low, int high) {
    int pivot = students[high].score;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (students[j].score <= pivot) {
            i++;
            std::swap(students[i], students[j]);
        }
    }

    std::swap(students[i + 1], students[high]);
    return i + 1;
}

// Реализация сортировки вставкой
void insertionSort(std::vector<Student>& students) {
    int n = students.size();
    for (int i = 1; i < n; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].score > key.score) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Student> students;
    students.push_back(Student("Мохов Глеб Генадьевич", 80));
    students.push_back(Student("Мороз Ксения Ивановна", 90));
    students.push_back(Student("Скала Джонсон", 70));
    students.push_back(Student("Егор Ярошенко", 85));

    // Сортировка с использованием QuickSort
    quickSort(students, 0, students.size() - 1);

    std::cout << "Сортировка с использованием QuickSort:" << std::endl;
    for (const auto& student : students) {
        std::cout << "Имя: " << student.name << ", Счёт: " << student.score << std::endl;
    }

    // Сортировка с использованием сортировки вставкой
    insertionSort(students);

    std::cout << "Сортировка методом вставки:" << std::endl;
    for (const auto& student : students) {
        std::cout << "Имя: " << student.name << ", Счёт: " << student.score << std::endl;
    }

    return 0;
}


