#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>


template <typename T>
void mySwap(T& a, T& b) {
    T temp = a; // Сохраняем значение a
    a = b;      // Присваиваем значение b a
    b = temp;   // Обновляем b временным значением
}

template <typename Container>
std::string container_to_string(const Container& container) {
    std::ostringstream oss;
    for (const auto& element : container) {
        oss << element << " "; // элемент
    }
    std::string result = oss.str();
    if (!result.empty()) {
        result.pop_back(); // - последний пробел
    }
    return result;
}

int main() {
    // Пример 
    int x = 10, y = 20;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    mySwap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    std::string str1 = "Hello", str2 = "World";
    std::cout << "Before swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
    my

