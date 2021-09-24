/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:42:13 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/24 22:01:41 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index <= 1)
	{
		return (index);
	}
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
