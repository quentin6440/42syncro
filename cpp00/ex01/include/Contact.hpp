/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:34:29 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/08 14:34:30 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
    private:
        std::string		name;
		std::string  	surname;
		std::string  	nickname;
		std::string  	phoneNumber;
		std::string  	secret;

    public:
        bool    	setInfo();
        void    	displayInfo();
		std::string	getName();
		std::string	getSurname();
		std::string	getNickname();
};

#endif