/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:39:43 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/14 12:50:54 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	result_div;
	int	result_mod;

	result_div = a / b;
	result_mod = a % b;
	*div = result_div;
	*mod = result_mod;
}
