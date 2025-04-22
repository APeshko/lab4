#ifndef MY_VECTOR_H 
#define MY_VECTOR_H

#include <algorithm> // Для std::copy
#include <initializer_list> // Для списковой инициализации
#include <utility>   // Для std::move

template <typename T>
class MyVector { //шаблонный класс хранящий тип Т
private:
    T* data;        //  указатель на массив элементов.
    size_t size;    // Текущее количество элементов
    size_t capacity; // Общий размер выделенной памяти

public:
    // 1. Конструкторы --------------------------------------------------------
    
    // Конструктор по умолчанию (пустой вектор)
    MyVector() : data(nullptr), size(0), capacity(0) {}
    
    // Конструктор с заданным размером
    explicit MyVector(size_t n) 
        : data(new T[n]), size(n), capacity(n) {} // Выделяем память сразу
    
    // Конструктор из списка инициализации {1, 2, 3}
    MyVector(std::initializer_list<T> init) 
        : data(new T[init.size()]), size(init.size()), capacity(init.size()) {
        std::copy(init.begin(), init.end(), data); // Копируем элементы
    }
    
    // 2. Деструктор ----------------------------------------------------------
    ~MyVector() {
        delete[] data; // Освобождаем память
    }
    
    // 3. Копирующие операции -------------------------------------------------
    
    // Конструктор копирования (глубокое копирование)
    MyVector(const MyVector& other) 
        : data(new T[other.capacity]), size(other.size), capacity(other.capacity) {
        std::copy(other.data, other.data + size, data);
    }
    
    // Оператор присваивания копированием
    MyVector& operator=(const MyVector& other) {
        if (this != &other) { // Защита от самоприсваивания
            delete[] data; // Удаляем старые данные
            
            data = new T[other.capacity]; // Выделяем новую память
            size = other.size;
            capacity = other.capacity;
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }
    
    // 4. Перемещающие операции -----------------------------------------------
    
    // Move-конструктор (noexcept для оптимизации)
    MyVector(MyVector&& other) noexcept 
        : data(other.data), size(other.size), capacity(other.capacity) {
        other.data = nullptr; // "Обнуляем" исходный объект
        other.size = 0;
        other.capacity = 0;
    }
    
    // Move-оператор присваивания
    MyVector& operator=(MyVector&& other) noexcept {
        if (this != &other) {
            delete[] data; // Освобождаем текущие ресурсы
            
            // "Перехватываем" ресурсы
            data = other.data;
            size = other.size;
            capacity = other.capacity;
            
            // Обнуляем исходный объект
            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }
    
    // 5. Методы доступа ------------------------------------------------------
    
    T& operator[](size_t index) {
        return data[index]; // Доступ без проверки границ (как в std::vector)
    }
    
    const T& operator[](size_t index) const {
        return data[index]; // Константная версия
    }
    
    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    
    // 6. Управление памятью --------------------------------------------------
    
    void reserve(size_t newCapacity) {
        if (newCapacity > capacity) {
            T* newData = new T[newCapacity]; // Новая память
            std::copy(data, data + size, newData); // Копируем элементы
            delete[] data; // Удаляем старую память
            data = newData;
            capacity = newCapacity;
        }
    }
    
    void push_back(const T& value) {
        if (size == capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2); // Увеличиваем емкость
        }
        data[size++] = value; // Добавляем элемент
    }
};

#endif // MY_VECTOR_H
