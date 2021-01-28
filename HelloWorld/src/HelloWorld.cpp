#include <cstdio>
#include "Config.h"
#include <cstdlib>
#include <ios>
#include <ostream>
#include <string>
#include <vector>
#include <iostream>
#include "interpolate.h"
#include <array>
#include <tuple>
#include <type_traits>
#include <string_view>


namespace a::b::c
{
    inline constexpr std::string_view str{ "hello" };
}
 
template <class... T>
std::tuple<std::size_t, std::common_type_t<T...>> sum(T... args)
{
    return { sizeof...(T), (args + ...) };
}
 

int main(int argc, char *argv[])
{
    // output the program location and version
    printf("Running: %s\nVersion: %i.%i\n", argv[argc-argc],        
            VERSION_MAJOR, VERSION_MINOR); 
    
    std::string s1("test string");
    std::vector<double> v1;
    v1.push_back(22.0);

    float t = 0.0f;     // elapsed time
    float b = 10.0f;    // start value
    float c = 20.0f;    // change value
    float d = 5.0f;     // duration

    // output argument values
    printf("t - %4.3f\nb - %4.3f\nc - %4.3f\nd - %4.3f\n\n",
        t, b, c, d);
    
    // output headings
    printf("%-20s%s\n", "Value", "Elapsed Time");
    printf("%-20s%s\n", "-----", "------------");

    // simulate values
    for (t=0.0f; t < d; t+= .25f) {
        printf("%-20.3f%4.3f secs\n",
            animation::linear(t,b,c,d), t);
    }

    printf("\n-> Simulation finished...\n");

    
    auto [iNumbers, iSum]{ sum(1, 2, 3) };
    std::cout << a::b::c::str << ' ' << iNumbers << ' ' << iSum << '\n';
 
    std::array arr{ 1, 2, 3 };
 
    std::cout << std::size(arr) << '\n';
 

    std::cout << "Let's configure chickn pie YCM!" << std::endl; 

    printf("Hello, Cmake!\n");
    return 0;
}
