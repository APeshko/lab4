#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>


template <typename T>
void mySwap(T& a, T& b) {
    T temp = a; 
    a = b;      
    b = temp;  
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
    // Пример с вектором
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Vector to string: " << container_to_string(vec) << std::endl;

    // Пример со списком
    std::list<std::string> lst = {"Hi", "oWn", "from", "Doll"};
    std::cout << "List to string: " << container_to_string(lst) << std::endl;

    // Пример с множеством
    std::set<char> mySet = {'a', 'b', 'c', 'd'};
    std::cout << "Set to string: " << container_to_string(mySet) << std::endl;

    return 0;
}

