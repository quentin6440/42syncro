
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

	// |0000 0000|0000 0000|0000 0000|0000 0000|
	int					rawBits;
	static const int	fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int value);
		Fixed(const float value);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif // FIXED_HPP
