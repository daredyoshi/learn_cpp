#include <ios>
#include <iostream>
#include <istream>
#include <string>
#include <limits>

class Fraction{
private:
    int m_numerator{0};
    int m_deonominator{0};
public:
    Fraction(int n=0, int d=0):
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
    friend std::ostream& operator<< (std::ostream &out, const Fraction &fraction);
    friend std::istream& operator>> (std::istream &in, Fraction &fraction);
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

std::ostream& operator<< (std::ostream &out, const Fraction &fraction){
    out << fraction.m_numerator << "/" << fraction.m_deonominator;
    return out;
}

std::istream& operator>> (std::istream &in, Fraction &fraction){
    in >> fraction.m_numerator;
    in >> fraction.m_deonominator;

    return in;
}

int main()
{
    Fraction f1{};
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;
 
	Fraction f2{};
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;
 
	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value
  
    return 0;
}
