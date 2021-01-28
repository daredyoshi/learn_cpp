#include <iostream>
#include <iterator>
#include <utility>
 
int main()
{
	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	constexpr int length{ static_cast<int>(std::size(array)) };

    bool swapped { };
    int num_iterations { 0 };
	// Step through each element of the array
	// (except the last one, which will already be sorted by the time we get there)
    do{
        swapped = false;

        for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
        {
            if (array[startIndex] > array[startIndex + 1]){
                std::swap(array[startIndex], array[startIndex + 1]);
                swapped = true;
            }
        }
        ++num_iterations;
    }
    while( swapped == true );
    
    std::cout << "Early termination on iteration " << num_iterations << '\n';
	// Now that the whole array is sorted, print our sorted array as proof it works
	for (int index{ 0 }; index < length; ++index)
		std::cout << array[index] << ' ';
     
	std::cout << '\n';
 
	return 0;
}
