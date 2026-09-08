/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:34:47 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/08 15:04:12 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include "Contact.hpp"
#include <cstdio>

class   Phonebook
{

    private:
        Contact contacts[8];
        std::size_t index;
        std::size_t ct;

    public:
        Phonebook();
        void    addContact();
        void    searchContact();
        void	displayTab();
};
#endif