// MyVector.h
#include <algorithm>
#include <initializer_list>

template <typename T>
class MyVector {
    T* data;
    size_t size;
    size_t capacity;

public:
    // Конструкторы
    MyVector() : data(nullptr), size(0), capacity(0) {}
    explicit MyVector(size_t n) : data(new T[n]), size(n), capacity(n) {}
    MyVector(std::initializer_list<T> init);
    
    // Деструктор
    ~MyVector() { delete[] data; }
    
    // Копирование
    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& other);
    
    // Перемещение
    MyVector(MyVector&& other) noexcept;
    MyVector& operator=(MyVector&& other) noexcept;
    
    // Методы доступа
    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }
    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    
    // Вспомогательные методы
    void reserve(size_t newCapacity);
    void push_back(const T& value);
};
