#include <iostream>
#include <cassert>
#include <array>

class Stack{
    using container_type = std::array<int, 10>;
    using size_type = container_type::size_type;


    container_type m_array;
    size_type m_next {0};

public:
    void reset(){
        m_next = 0;
    }
    bool push(int value){
        
        if(m_next == m_array.size())
            return false;

        m_array[m_next++] = value; // remember that++ after the variable increments it after evaluation
        return true;
    }

    int pop(){
        assert (m_next > 0 && "Can not pop empty stack");
        return m_array[--m_next]; // remember that -- BEFORE the varialbes incremembts it before eval
    }    

    void print(){
        std::cout << "(  ";
        for(size_type stackIdx{0}; stackIdx < m_next; ++stackIdx){
            std::cout << m_array[stackIdx] << ' ';
        }
        std::cout << " )";
    }

};

int main()
{
	Stack stack;
	stack.reset();
 
	stack.print();
 
	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();
 
	stack.pop();
	stack.print();
 
	stack.pop();
	stack.pop();
 
	stack.print();
 
	return 0;
}

