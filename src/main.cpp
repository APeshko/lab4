#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include "MyVector.h"
#include "MyArray.h"
#include "utils.h"

using namespace std;
using namespace std::chrono;

void performanceTest() {
    const size_t SIZE = 1000000;
    
    // Создаем большой вектор
    MyVector<int> v1(SIZE);
    for(size_t i = 0; i < SIZE; ++i) {
        v1[i] = i;
    }
    
    // Тест копирования
    auto start = high_resolution_clock::now();
    MyVector<int> v2 = v1; // копирование
    auto end = high_resolution_clock::now();
    cout << "Copy time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    
    // Тест перемещения
    start = high_resolution_clock::now();
    MyVector<int> v3 = move(v1); // перемещение
    end = high_resolution_clock::now();
    cout << "Move time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
}

void templateFunctionsDemo() {
    // Демонстрация mySwap
    int a = 5, b = 10;
    cout << "Before swap: a=" << a << ", b=" << b << endl;
    mySwap(a, b);
    cout << "After swap: a=" << a << ", b=" << b << endl;
    
    // Демонстрация containerToString
    vector<int> vec = {1, 2, 3};
    list<string> lst = {"hello", "world"};
    set<double> s = {1.1, 2.2, 3.3};
    
    cout << "Vector: " << containerToString(vec) << endl;
    cout << "List: " << containerToString(lst) << endl;
    cout << "Set: " << containerToString(s) << endl;
}

void myArrayDemo() {
    MyArray<string, 3> arr;
    arr[0] = "First";
    arr[1] = "Second";
    arr[2] = "Third";
    
    cout << "MyArray contents: ";
    for(const auto& s : arr) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== Performance Test ===" << endl;
    performanceTest();
    
    cout << "\n=== Template Functions Demo ===" << endl;
    templateFunctionsDemo();
    
    cout << "\n=== MyArray Demo ===" << endl;
    myArrayDemo();
    
    return 0;
}
