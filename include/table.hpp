#ifndef FORMAT_TABLE_HPP
#define FORMAT_TABLE_HPP

template<typename T>
class cell {
public:
    cell();
    cell(T value);

    void setValue(T value);
    T getValue();

private:
    T val;
};

class formatTable {
public:

};

#endif