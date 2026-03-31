#ifndef CLASS_INTEGER_HPP
#define CLASS_INTEGER_HPP

class Integer {
private:
    int data;

public:
    Integer() = delete;
    Integer(const int &x) : data(x) {}
    Integer(const Integer &) = default;
    Integer &operator=(const Integer &) = default;
    ~Integer() = default;

    bool operator==(const Integer &rhs) const { return data == rhs.data; }
    bool operator!=(const Integer &rhs) const { return data != rhs.data; }
};

#endif

