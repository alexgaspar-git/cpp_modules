/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:32:25 by algaspar          #+#    #+#             */
/*   Updated: 2023/02/23 14:08:42 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	_name = name;
}

Zombie::~Zombie() {
	std::cout << _name << " has been destroyed." << std::endl;
}

void	Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}