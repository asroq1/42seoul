/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:02:47 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/05 18:44:55 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &obj);
	void attack(const std::string &target);
	void guardGate();
};

#endif