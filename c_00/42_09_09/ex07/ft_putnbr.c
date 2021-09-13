/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:11:18 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/13 21:55:46 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (9 >= nb && nb >= 0)
		ft_putchar(nb + '0');
	else if (nb == -2147483648)
	{
		ft_putnbr(-2);
		ft_putnbr(147483648);
	}
	else if ( nb != -2147483648 && nb < 0)
	{
		//-42가 나오는 이유는 재귀 덕분에 결과의 반전이 생긴다.
		ft_putchar('-');
		ft_putnbr(nb * (-1));
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
//참고 : https://sciphy.tistory.com/874
