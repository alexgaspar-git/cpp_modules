/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:27:36 by algaspar          #+#    #+#             */
/*   Updated: 2023/02/23 13:16:19 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class PhoneBook {

private:
	Contact _contact[8];
	int		_index;

public:
	PhoneBook();
	void	addContact();
	void	searchContact();
};


#endif