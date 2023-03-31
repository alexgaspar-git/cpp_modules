/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:14:17 by algaspar          #+#    #+#             */
/*   Updated: 2023/02/23 15:02:44 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {

	Zombie *zomb = new Zombie[N];
	Zombie z(name);
	for (int i = 0; i < N; i++) {
		zomb[i] = z;
	}
	return zomb;
}
