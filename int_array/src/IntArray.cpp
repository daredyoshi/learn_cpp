#include "IntArray.h"
#include <cassert>

IntArray::IntArray(int amount){
        assert (amount > 0 && "Array should be a positive length");

        m_array = new int[amount]{}; 
        m_length = amount;
}

IntArray::IntArray(IntArray &source){
    deepCopy(source);
}

void IntArray::deepCopy(const IntArray& source){
    // first we need to deallocate any value that the string is holding!
    delete[] m_array;

    m_length= source.m_length;

    // m_array is a pointer, so we need to deep copy it if it is non-null
    if(source.m_array){
        // allocate memory for our copy
        m_array = new int[m_length];

        // do the copy
        for (int i{ 0 }; i < m_length; ++i){
            m_array[i] = source.m_array[i];
        }
    }
    else{
        m_array = nullptr;
    }

}

IntArray& IntArray::operator=(const IntArray& source){
    // check for self-assignment
    if (this != &source){
        deepCopy(source);
    }

    return *this;
}

int& IntArray::operator[](int i){
    assert (i < m_length && "Index outside of range!");
    assert (i >= 0 );
    return m_array[i];
}

std::ostream& operator<< (std::ostream &out, const IntArray &array){

    for(int i {0}; i<array.m_length; ++i){
        out<<array.m_array[i]<< ' ';
    }
    return out;
}



