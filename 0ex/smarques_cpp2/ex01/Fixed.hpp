/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 00:38:08 by Samuel            #+#    #+#             */
/*   Updated: 2026/09/25 20:08:01 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					fpValue;
		static const int	bits;

	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		int		getRawBits() const;
		void	setRawBits(int const raw);

		//new
		Fixed(const int nbr);
		Fixed(const float nbr);
		float	toFloat() const;
		int		toInt() const;
		//

		~Fixed();
};

	std::ostream &operator<<(std::ostream &ostrm, Fixed const &nbr);

#endif
