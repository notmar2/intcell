#include "IntCell.h"

IntCell::IntCell(int newValue) : storedValue(newValue) {}

IntCell::IntCell(const IntCell &rhs) : storedValue(rhs.storedValue) {}

IntCell::IntCell(IntCell &&rhs) noexcept : storedValue(rhs.storedValue) {}

IntCell &IntCell::operator=(const IntCell &rhs) {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
    }
    return *this;
}

IntCell &IntCell::operator=(IntCell &&rhs) noexcept {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }
    return *this;
}

IntCell &IntCell::operator=(int rhs) {
    storedValue = rhs;
    return *this;
}

IntCell &IntCell::operator+(const IntCell &rhs) {
    storedValue = storedValue + rhs.storedValue;
    return *this;
}

IntCell &IntCell::operator+(int rhs) {
    storedValue = storedValue + rhs;
    return *this;
}

IntCell &IntCell::operator-(const IntCell &rhs) {
    storedValue = storedValue - rhs.storedValue;
    return *this;
}

IntCell &IntCell::operator-(int rhs) {
    storedValue = storedValue - rhs;
    return *this;
}

int IntCell::getValue() const {
    return storedValue;
}

void IntCell::setValue(int newValue) {
    storedValue = newValue;
}
