#include <iostream>
#include <chrono>
#include "MyVector.h"
#include "utils.h"

void performanceTest() {
    const size_t SIZE = 1000000;
    
    // Создаем большой вектор
    MyVector<int> v1(SIZE);
    for (size_t i = 0; i < SIZE; ++i) {
        v1[i] = i;
    }
    
    // Тест копирования
    auto start = std::chrono::high_resolution_clock::now();
    MyVector<int> v2 = v1;  // Копирование
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Copy time: " << diff.count() << " s\n";
    
    // Тест перемещения
    start = std::chrono::high_resolution_clock::now();
    MyVector<int> v3 = std::move(v1);  // Перемещение
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Move time: " << diff.count() << " s\n";
}
