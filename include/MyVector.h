#include <algorithm>
#include <initializer_list>

template <typename T>
class MyVector {
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

public:
    MyVector() = default;
    explicit MyVector(size_t size);
    MyVector(std::initializer_list<T> init);
    
    ~MyVector();
    
    MyVector(const MyVector& other);

    MyVector& operator=(const MyVector& other);
    
    // Move кон
    MyVector(MyVector&& other) noexcept;
    
    // Move о_п
    MyVector& operator=(MyVector&& other) noexcept;
    
    // Методы доступа
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t getSize() const;
    size_t getCapacity() const;
    
    // Методы модификации
    void push_back(const T& value);
    void push_back(T&& value);
    void reserve(size_t newCapacity);
};
