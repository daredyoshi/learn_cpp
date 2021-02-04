#include <iostream>

class IntPair{
public:
    int x{};
    int y{};

    void set(int newX, int newY){
        x = newX;
        y = newY;
    }

    void print(){
        std::cout << "X = " << x <<  '\n';
        std::cout << "Y = " << y << '\n';
    }
};

int main()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)
	
	IntPair p2{ 2, 2 }; // initialize p2 values to (2, 2)
 
	p1.print();
	p2.print();
 
	return 0;
}

