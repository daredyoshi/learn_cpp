
#include <iostream>
#include "constants.h" 

double calculateHeight(double initialHeight, int seconds){
    double distanceFallen = myConstants::gravity * seconds * seconds / 2;
    double heightNow = initialHeight - distanceFallen;

    // Check whether we've gone under the groun
    // If so, set the height to ground-level
    if (heightNow < 0.0){
        return 0.0;
    }
    else{
        return heightNow;
    }
}

int main(){
    using namespace std;
    cout << "Enter the initial height of the tower in meters: ";
    double currentHeight;
    cin >> currentHeight;

    long t = 0;
    while(currentHeight > 0){
        currentHeight = calculateHeight(currentHeight, t);
        std::cout << "At " << t << " seconds, the ball is at height: " << currentHeight << "\n";
        ++t;
    }

    
    return 0;
}


