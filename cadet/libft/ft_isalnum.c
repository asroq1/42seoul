/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:07:12 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/09 16:35:51 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int arg)
{
	if (arg >= 'a' || arg <= 'z' || arg >= 'A' || arg <= 'Z' )
	{
		return (1);
	}
	else if (arg >= 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
