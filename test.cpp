#include <iostream>

class Test{
public:
    Test() = default; 

    int get(){
        return testInt;
    }

private:
    int testInt;
};

int main(){
    Test t;
    std::cout << t.get() << std::endl; // prints 0
}

class IntCell{
public:
    IntCell(const IntCell &rhs) 
        : storedValue(rhs.storedValue) {}

    void setValue(const int value){
        this->storedValue = value;
    }

    int getValue(){
        return this->storedValue;
    }

private:
    int storedValue;
};