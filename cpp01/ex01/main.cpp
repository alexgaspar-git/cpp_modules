/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:06:21 by algaspar          #+#    #+#             */
/*   Updated: 2023/02/23 15:04:32 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *zomb = zombieHorde(10, "Jeff");
	for (int i = 0; i < 10; i++) {
		zomb[i].announce();
	}
	delete[] zomb;
	return 0;
}