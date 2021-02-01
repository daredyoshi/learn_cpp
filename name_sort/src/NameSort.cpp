#include <bits/c++config.h>
#include <iostream>
#include <iterator>
#include <utility>
#include <limits>

std::size_t getNameCount(){

    std::cout << "How many times would you like to enter? ";
    int numNames {0};
    std::cin >> numNames;

    return numNames;
}

int main()
{
    std::size_t numNames {getNameCount()};

    std::string *names{ new std::string[numNames]{} };
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    for ( std::size_t nameIndex{ 0 }; nameIndex < numNames ; ++nameIndex ){
        std::string name {};    
        std::cout << "Enter Name #" << nameIndex << ":\n";
        std::getline(std::cin, name);
        // clear the buffer

        names[nameIndex] = name;
    }


    bool swapped { };
    int num_iterations { 0 };
	// Step through each element of the array
	// (except the last one, which will already be sorted by the time we get there)
    do{
        swapped = false;

        for (size_t startIndex{ 0 }; startIndex < numNames - 1; ++startIndex)
        {
            if (names[startIndex] > names[startIndex + 1]){
                std::swap(names[startIndex], names[startIndex + 1]);
                swapped = true;
            }
        }
        ++num_iterations;
    }
    while( swapped == true );
    
    std::cout << "Early termination on iteration " << num_iterations << '\n';
	// Now that the whole array is sorted, print our sorted array as proof it works
	for (size_t index{ 0 }; index < numNames; ++index)
		std::cout << names[index] << ' ';
     
	std::cout << '\n';
    delete[] names;
    names = nullptr;
 
	return 0;
}
