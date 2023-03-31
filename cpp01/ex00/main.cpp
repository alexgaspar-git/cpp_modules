/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:06:21 by algaspar          #+#    #+#             */
/*   Updated: 2023/02/23 14:11:00 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *zombo = newZombie("Pedro");
	zombo->announce();
	randomChump("Jeff");
	delete zombo;
	return 0;
}