#include <iostream>


int fractorial(int N){
    if(N <= 0){
        return 1;
    }
    return fractorial(N-1) * N;
}

long int triangular(long int N){
    if(N <= 0){
        return 0;
    }
    return triangular(N-1) + N;
}

long int sumNumbers(long int N){
    if (N<10){
        return N;
    }
    else{
        // keep dividing by 10 and adding the remainder that is left over from 
        // each recursion
        return sumNumbers(N / 10) + N % 10;
    }
}

void printBinary(int N){
    if (N >= 1){
        printBinary(N / 2);
    }
    std::cout << N % 2;
}

int main(void)
{
    std::cout << "Enter up to which fractorial you would like to calculate?\n";
    int N {0};
    std::cin >> N;
    std::cout << "The fractorial of " << N << " is " << fractorial(N) << " \n";
    
    std::cout << "Enter which triangular number you would like to calculate: \n";
    std::cin >> N;
    std::cout << "The " << N << "th triangular number is " << triangular(N) << " \n";

    std::cout << "Enter the numbers you would like to know the sum of: \n";
    std::cin >> N;
    std::cout << "The Sum of the numbers " << N << " is " << sumNumbers(N) << " \n";

    std::cout << "Enter a number you would like to print in binary: \n";
    std::cin >> N;
    std::cout << N << " in binary is ";
    printBinary(N);

    

    return 0;
}
