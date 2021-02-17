#include <exception>
#include <ios>
#include <iostream>
#include <istream>
#include <stdexcept>
#include <string>
#include <limits>

class Fraction{
private:
    int m_numerator;
    int m_deonominator;
public:
    Fraction(int n=1, int d=1):
        m_numerator{n} {
            // this will automatically be called by operators
            // that are overloaded because they return a new
            // Fraction object
            setD(d);
            reduce();
        }

    void print() const{
        std::cout << m_numerator << '/' << m_deonominator << '\n';
    }

    // this is to practice throwing exceptions.
    // usually this would just return a success or failuer (0, 1)
    // but we want to practice exceptions
    void setD(const int d) {
        if(d == 0){
            throw std::runtime_error("Invalid denominator");
        }
        else{
            m_deonominator = d;
        }
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
    int d{0};
    in >> d;
    fraction.setD(d);
    return in;
}

int main()
{
    try{
        Fraction f1{};
        std::cout << "Enter fraction 1: ";
        std::cin >> f1;
    }
    catch(std::exception& e){
        std::cout << e.what() << '\n';
    }
 
  
    return 0;
}
