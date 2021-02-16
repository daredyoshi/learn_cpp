#include <string>
#include <iostream>

template <class T>
class Pair1{
private:
    T m_a;
    T m_b;
public:
    Pair1 (const T& a, const T& b )
        : m_a{a}, m_b{b} {

        }
    
    const T& first() const { return m_a; }
    const T& second() const { return m_b; }

};

template <class T1, class T2>
class Pair{
private:
    T1 m_a;
    T2 m_b;
public:
    Pair (const T1& a, const T2& b )
        : m_a{a}, m_b{b} {

        }
    
    const T1& first() const { return m_a; }
    const T2& second() const { return m_b; }

};

template<class T>
class StringValuePair : public Pair<std::string, T>{
public:
    StringValuePair(const std::string& key, const T& value)
        : Pair<std::string, T>(key, value){

        }
};


int main(){
    Pair1<int> p1(5, 8);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
 
	const Pair1<double> p2(2.3, 4.5);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
 
    Pair<int, double> p3(5, 8.6);
	std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';
 
	const Pair<double, int> p4(2.3, 5);
	std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

    StringValuePair<int> svp("Hello", 5);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';


	return 0;
}
