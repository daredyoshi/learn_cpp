#include <ios>
#include <iostream>
#include <string>
#include <limits>

class Fraction{
private:
    int m_numerator{0};
    int m_deonominator{0};
public:
    Fraction(int n, int d):
        m_numerator{n}, m_deonominator{d} {
            // this will automatically be called by operators
            // that are overloaded because they return a new
            // Fraction object
            reduce();
        }

    void print() const{
        std::cout << m_numerator << '/' << m_deonominator << '\n';
    }

    
    int gcd(int a, int b) {
        return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }

    void reduce(){
        if (m_numerator != 0 && m_deonominator != 0){
            int gcd { Fraction::gcd(m_numerator, m_deonominator) };
            m_numerator /= gcd;
            m_deonominator /= gcd;
        }
    }

    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, const int i);
    friend Fraction operator*(const int i,const Fraction &f1);
};

// learning how to overload operators using the friend function
// the const is important because it's impossible to bind again
// non-const temp reference objects
Fraction operator*(const Fraction &f1, const Fraction &f2){
    return Fraction{
        f1.m_numerator * f2.m_numerator, 
        f1.m_deonominator * f2.m_deonominator            
    };
}

Fraction operator*(const Fraction &f1, const int i){
    return Fraction{
        f1.m_numerator * i,
        f1.m_deonominator * i,
    };
}

Fraction operator*(const int i,const Fraction &f1){
    return Fraction{
        f1.m_numerator * i,
        f1.m_deonominator * i,
    };
}

int main()
{
    Fraction f1{2, 5};
    f1.print();
 
    Fraction f2{3, 8};
    f2.print();
 
    Fraction f3{ f1 * f2 };
    f3.print();
 
    Fraction f4{ f1 * 2 };
    f4.print();
 
    Fraction f5{ 2 * f2 };
    f5.print();
 
    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();
  
    return 0;
}
