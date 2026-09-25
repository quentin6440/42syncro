
#include "Fixed.hpp"
#include <iostream>



int main( void ) {

	std::cout << "=== Subject test ===" << std::endl;


	Fixed a(4);
	Fixed b( 8 );
	Fixed c(42.42f);

	Fixed d(0);

	c = b;

	std::cout << (a++) << std::endl;
	std::cout << (--b) << std::endl;
	std::cout << ++d << std::endl;

}
