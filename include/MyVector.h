#ifndef MY_VECTOR_H 
#define MY_VECTOR_H

#include <algorithm> 
#include <initializer_list> // Для списковой инициализации
#include <utility>   // Для std::move

template <typename T>
class MyVector { //шаблонный класс хранящий тип Т
private:
    T* data;        //  указатель на массив элементов.
    size_t size;    // текущее количество элементов
    size_t capacity; // общий размер выделенной памяти

public:
    MyVector() : data(nullptr), size(0), capacity(0) {}
    explicit MyVector(size_t n) 
        : data(new T[n]), size(n), capacity(n) {} 
    MyVector(std::initializer_list<T> init) 
        : data(new T[init.size()]), size(init.size()), capacity(init.size()) {
        std::copy(init.begin(), init.end(), data); // Копируем элементы
    }
    
    ~MyVector() {
        delete[] data;
    }
       
    // Конструктор копирования
    MyVector(const MyVector& other) 
        : data(new T[other.capacity]), size(other.size), capacity(other.capacity) {
        std::copy(other.data, other.data + size, data);
    }
    
    // Оператор присваивания копированием
    MyVector& operator=(const MyVector& other) {
        if (this != &other) { // Защита от самоприсваивания
            delete[] data; // Удаляем старые данные
            
            data = new T[other.capacity]; // Выдел новую память
            size = other.size;
            capacity = other.capacity;
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }
    
    //перемещ операции
    
    // move-конструктор
    MyVector(MyVector&& other) noexcept 
        : data(other.data), size(other.size), capacity(other.capacity) {
        other.data = nullptr; // "Обнуляем" исходный объект
        other.size = 0;
        other.capacity = 0;
    }
    
    // move-оператор присваивания
    MyVector& operator=(MyVector&& other) noexcept {
        if (this != &other) {
            delete[] data; // Освобождаем текущие ресурсы
            
            // "Перехватываем" ресурсы
            data = other.data;
            size = other.size;
            capacity = other.capacity;
            
            // обнуление
            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }
    
    // методы доступа
    
    T& operator[](size_t index) {
        return data[index]; // Доступ без проверки границ (как в std::vector)
    }
    
    const T& operator[](size_t index) const {
        return data[index]; // Константная версия
    }
    
    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    
    // управление памятью
    
    void reserve(size_t newCapacity) {
        if (newCapacity > capacity) {
            T* newData = new T[newCapacity]; // new память
            std::copy(data, data + size, newData); // copir элементы
            delete[] data; // удал старую память
            data = newData;
            capacity = newCapacity;
        }
    }
    
    void push_back(const T& value) {
        if (size == capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2); // увеличи емкость
        }
        data[size++] = value; // Добавляем элемент
    }
};

#endif // MY_VECTOR_H
