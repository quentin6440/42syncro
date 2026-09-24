/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:34:52 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/08 17:33:11 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <string>

bool        readline(std::string &str);
bool	    ft_isnum(const std::string &s);
std::string	formatField(int i, const std::string &str);
void        printField(int i, const std::string &str);
void	printFormatted(int i,const std::string &str);
void	printFormattedL(int i,const std::string &str);

#endif