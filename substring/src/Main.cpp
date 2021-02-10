#include <ios>
#include <iostream>
#include <string>
#include <string_view>

// this is an exercise on overloading the () operator. 
// In this case it is to create a functor for substring
class Substring{
private:
    std::string m_string {};
public:
    Substring(std::string s):
        m_string{s} {}
    std::string operator() (int start, int end){
        return m_string.substr(start, end);
    }
};

int main()
{
  
    Substring string { "Hello, world!" };
    std::cout << string(7,5) << '\n'; 
    return 0;
}
