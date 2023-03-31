/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:25:51 by algaspar          #+#    #+#             */
/*   Updated: 2023/02/23 15:00:57 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {

private:
	std::string _name;

public:
	Zombie( std::string name );
	Zombie();
	~Zombie();
	void announce();

};

Zombie*	zombieHorde( int N, std::string name );

#endif