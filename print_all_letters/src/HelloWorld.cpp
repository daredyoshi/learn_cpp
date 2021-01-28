#include <iostream>

int main()
{
    std::cout << "Printing all the letters and ascii codes \n";
    int idx { 65 };
    while(idx <= 90){
        char c { static_cast<char>(idx) };
        std::cout << "The character " << c << " has ascii code " << idx << "\n";
        ++idx;
        
    }
    return 0;
}
