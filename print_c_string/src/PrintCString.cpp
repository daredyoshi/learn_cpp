#include <iostream>
#include <string>
#include <sstream>


void printCString(const char* str){
    do{
        std::cout << *str;
        ++str;
    }while(*str != '\0');
}

int main()
{
    
    // print once for the user to see
    std::cout << "Testing printing following C string:\n";
    printCString("Hello world!");
    std::cout << "\n";
    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
    // BEGIN: Code being tested
    printCString("Hello world!");

    // END: Code being tested
    std::string text = buffer.str();
    std::string expected = "Hello world!";

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);

    if(text != expected){
        std::cout << "Printing C style string failed";
    }
    else{
        std::cout << "Printing proceeded correctly";
    }
     
    return 0;
}
