/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:34:52 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/08 14:34:53 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <string>

bool        readline(std::string &str);
bool	    ft_isnum(const std::string &s);
std::string	formatField(const std::string &str);
void        printField(const std::string &str);

#endif