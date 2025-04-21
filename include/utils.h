// utils.h
#include <sstream>
#include <type_traits>
#include <vector>
#include <list>
#include <set>

template <typename T>
void mySwap(T& a, T& b) {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

template <typename Container>
std::string containerToString(const Container& c) {
    std::ostringstream oss;
    oss << "[";
    bool first = true;
    for (const auto& item : c) {
        if (!first) oss << ", ";
        oss << item;
        first = false;
    }
    oss << "]";
    return oss.str();
}
