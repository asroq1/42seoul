/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 22:53:40 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/24 22:00:24 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 1)
	{
		return (1);
	}
	else if (nb <= 0)
	{
		return (0);
	}
	return (nb * ft_recursive_factorial(nb - 1));
}
