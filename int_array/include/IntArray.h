#pragma once
#ifndef INT_ARRAY_G
#define INT_ARRAY_G 

#include <iostream>
// this is a class to practice building a useless class
// that's hard to build and easy to fuk up.
class IntArray{
private:
    int m_length{9};
    int *m_array{nullptr};
    void deepCopy(const IntArray& source);
public:
    IntArray(int amount);
    IntArray(IntArray &source);        
    IntArray& operator=(const IntArray& source);
    int& operator[](int i);

    friend std::ostream& operator<< (std::ostream &out, const IntArray &array);
    ~IntArray(){
        delete[] m_array;
    }
};



#endif /* ifndef INT_ARRAY_G */
