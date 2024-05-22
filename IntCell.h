#ifndef INTCELL_H
#define INTCELL_H

class IntCell {
public:
    IntCell() = default;
    IntCell(int newValue = 0);
    IntCell(const IntCell &rhs);
    IntCell(IntCell &&rhs) noexcept;
    ~IntCell() = default;

    IntCell &operator=(const IntCell &rhs);
    IntCell &operator=(IntCell &&rhs) noexcept;
    IntCell &operator=(int rhs);
    IntCell &operator+(const IntCell &rhs);
    IntCell &operator+(int rhs);
    IntCell &operator-(const IntCell &rhs);
    IntCell &operator-(int rhs);

    int getValue() const;
    void setValue(int newValue);

private:
    int storedValue;
    int storedValue2;
    int storedValue3;
};

#endif  // INTCELL_H
