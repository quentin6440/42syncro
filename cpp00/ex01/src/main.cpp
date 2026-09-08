/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:35:07 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/08 15:00:48 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"
#include "../include/Phonebook.hpp"
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
           std::cout <<"no valid entry, quitting...\n";
            break;
        }
        if (param == "exit" || param == "q")
        {
           std::cout <<"exit then, quitting...\n";
           break ;
        }
        if (param == "add" || param == "a")
            myphonebook.addContact();
        if (param == "search" || param == "s")
            myphonebook.searchContact();
     }
    return 0;
}