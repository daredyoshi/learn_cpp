#include <cstdint>
#include <iostream>


class RGBA{
    using fint=std::uint_fast8_t; 
private:

    fint m_red {};
    fint m_green {};
    fint m_blue {};
    fint m_alpha {};

public:
    RGBA(fint red=0, fint green=0, fint blue=0, fint alpha=0) :
        m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha }{}

    void print(){
        std::cout << "r=" << static_cast<int>(m_red) 
            << " g=" << static_cast<int>( m_green )
            << " b=" << static_cast<int>( m_blue  )
            << " a=" << static_cast<int>( m_alpha );
    }
};

int main()
{
	RGBA teal{ 0, 127, 127 };
	teal.print();
 
	return 0;
}
