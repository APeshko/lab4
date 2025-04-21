
template <typename T, size_t N>
class MyArray {
    T data[N];
    
public:
    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }
    
    size_t size() const { return N; }
    
    T* begin() { return data; }
    const T* begin() const { return data; }
    
    T* end() { return data + N; }
    const T* end() const { return data + N; }
};
