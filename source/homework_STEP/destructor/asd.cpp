#define START
#include <iostream>

int main()
{
#ifdef START
std::cout << "Hello world" << std::endl;
#else
std::cout << "Suck world" << std::endl;
#endif

}
