#include <ios>
#include <iostream>
#include <string>
#include <limits>


struct Fraction{
    int numerator;
    int denominator;
};


double multiply(Fraction fraction_a, Fraction fraction_b){
    double fraction_a_result = static_cast<float>(fraction_a.numerator) / static_cast<float>(fraction_a.denominator);
    double fraction_b_result = static_cast<float>(fraction_b.numerator) / static_cast<float>(fraction_b.denominator);
    return fraction_a_result * fraction_b_result;
}

int main()
{
    Fraction fraction_a;
    Fraction fraction_b;
    
    std::cout << "Please enter your first fraction numerator: ";
    std::cin >>  fraction_a.numerator; 

    std::cout << "Please enter your first denominator: ";
    std::cin >> fraction_a.denominator;
    
    std::cout << "Please enter your second fraction numerator: ";
    std::cin >>  fraction_b.numerator; 

    std::cout << "Please enter your second denominator: ";
    std::cin >> fraction_b.denominator;

    std::cout << "The sum of your fractions is " << multiply(fraction_a, fraction_b);

    return 0;
}
