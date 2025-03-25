#include<iostream>

template <typename T, typename U>
int x = 10;  // A template variable declaration (does not affect the class template)

template <typename T, typename U>
class MyClass {
private:
    T value1;
    U value2;

public:
    MyClass(T val1, U val2) : value1(val1), value2(val2) {}

    void printValues() {
        std::cout << "Value1: " << value1 << ", Value2: " << value2 << std::endl;
    }
};

int main() {
    MyClass<int, double> obj(42, 3.14);
    obj.printValues();
    
    // x is just a template variable, not directly affecting the class
    std::cout << "x<int, double>: " << x<int, double> << std::endl; // Output: 10
    return 0;
}