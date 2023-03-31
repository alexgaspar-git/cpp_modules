/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:18:41 by algaspar          #+#    #+#             */
/*   Updated: 2023/01/10 15:54:31 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	std::string s;

	if (argc == 1)
		s = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; argv[i]; i++)
			s.append(argv[i]);
		std::string::size_type n = s.length();
		for (std::string::size_type i = 0; i < n; i++) {
			s.at(i) = toupper(s.at(i));
		}
	}
	std::cout << s << std::endl;
	return 0;
}
