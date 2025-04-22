#include <iostream>
#include <stdexcept> // Для std::out_of_range
#include <string>

template <typename T, size_t Size>
class MyArray {
private:
    T data[Size]; // static м size=const

public:
    // Конструктор по умолчанию не нужен для статического м? да

    // М для доступа к элементам м
    T& operator[](size_t index) {
        if (index >= Size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Конст метод доступа для чтения элементов м
    const T& operator[](size_t index) const {
        if (index >= Size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t getSize() const {
        return Size;
    }
    void fill(const T& value) {
        for (size_t i = 0; i < Size; ++i) {
            data[i] = value;
        }
    }

    void print() const {
        for (size_t i = 0; i < Size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // для массива типа int
    MyArray<int, 5> intArray;
    intArray.fill(0); //0
    intArray[0] = 1;
    intArray[1] = 2;
    intArray[2] = 3;
    intArray[3] = 4;
    intArray[4] = 5;

    std::cout << "Int array: ";
    intArray.print(); 

    // типа std::string
    MyArray<std::string, 5> strArray;
    strArray.fill("default"); // default
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "from";
    strArray[3] = "MyArray";
    strArray[4] = "class";

    std::cout << "String array: ";
    strArray.print(); 

    // Выводим размер массива
    std::cout << "Size of intArray: " << intArray.getSize() << std::endl;
    std::cout << "Size of strArray: " << strArray.getSize() << std::endl;

    return 0;
}

