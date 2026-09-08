/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:35:07 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/08 17:39:41 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"
#include "Phonebook.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>

int main(void) {

    Phonebook myphonebook;

    std::string param;

    std::cout << "Hello\n";

    while (true)
    {
        std::cout << "\n-- phonebook -- add, search or exit ! cheers\n /-> : " ; 
        if(!readline(param))
        {
           std::cout <<"Quitting...\n";
            break;
        }
        if (param == "EXIT")
        {
           std::cout <<"Exit then, quitting...\n";
           break ;
        }
        if (param == "ADD")
            myphonebook.addContact();
        if (param == "SEARCH")
            myphonebook.searchContact();
     }
    return 0;
}