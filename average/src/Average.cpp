#include "Average.h"

double Average::value() const{
   return static_cast<double>(m_sum) / static_cast<double>(m_amount); 
}

Average& Average::operator+=(int v){
    m_sum += v;
    ++m_amount;
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Average &a){
    std::cout << a.value();    
    return out;
}
