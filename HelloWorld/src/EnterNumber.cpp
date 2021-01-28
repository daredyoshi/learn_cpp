#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x{}; // define variable x
    std::cin >> x; // get a number from keyboard and store it in x
    std::cout << "You entered " << x << "\n";
    return 0;
}
