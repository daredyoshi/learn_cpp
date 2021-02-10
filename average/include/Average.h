#pragma once
#ifndef AVERAGE_H
#define AVERAGE_H 
#include <iostream>

class Average{
private:
    std::int_least32_t m_sum {0};
    std::int_least8_t m_amount {0};

    double value() const;

public:
    Average& operator+=(int v);
    friend std::ostream& operator<< (std::ostream &out, const Average &a);
};


#endif /* ifndef AVERAGE_H */
