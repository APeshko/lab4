#include <stdexcept>

template <typename T, size_t N>
class MyArray {
private:
    T data[N];

public:
    // Доступ к элементам
    T& operator[](size_t index) {
        if (index >= N) throw std::out_of_range("Index out of range");
        return data[index];
    }
    
    const T& operator[](size_t index) const {
        if (index >= N) throw std::out_of_range("Index out of range");
        return data[index];
    }
    
    constexpr size_t size() const { return N; }
    
    T* begin() { return data; }
    const T* begin() const { return data; }
    T* end() { return data + N; }
    const T* end() const { return data + N; }
};
