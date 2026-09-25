
#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

	// |0000 0000|0000 0000|0000 0000|0000 0000|
	int					rawBits;
	static const int	fractionalBits = 8;

	public:
		Fixed();								// 0. Default Constructor
		~Fixed();								// 1. Destructor
		Fixed(const Fixed& other);				// 2. Copy constructor
		Fixed& operator=(const Fixed& other);	// 3. Copy assignment operator

		int getRawBits( void ) const;
		void setRawBits( int const raw );

};

#endif // FIXED_HPP
