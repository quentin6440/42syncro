#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_fxpValue;
		static const int	_fractionalBits;

	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		~Fixed();

		Fixed(const int value);
		Fixed(const float value);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
};

	std::ostream &operator<<(std::ostream &ostrm, Fixed const &nbr);

#endif