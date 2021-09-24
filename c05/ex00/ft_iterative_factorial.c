/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 22:21:53 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/24 21:59:59 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;

	n = 1;
	if (nb == 0)
	{
		return (0);
	}
	while (nb != 1)
	{
		n *= nb;
		nb--;
	}
	return (n);
}
