/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:14:11 by hyunjung          #+#    #+#             */
/*   Updated: 2021/11/17 19:58:12 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	size_t			idx;

	idx = 0;
	if (dest <= src)
	{
		new_dest = (unsigned char *)dest;
		new_src = (unsigned char *)src;
		while (idx < size)
		{
			*new_dest++ = *new_src;
			idx++;
		}
	}
	else
	{
		new_dest = dest + (size - 1);
		new_src = src + (size - 1);
		while (idx < size)
		{
			*new_dest-- = *new_src--;
			idx++;
		}
	}
	return (dest);
}


int main(void)
{
    char str[] = "BlockDMask";
 
    // 메모리 복사 : 메모리 겹침
 
    memmove(str, str + 2, sizeof(char) * 4);
    // source
	printf("------original-----\n");
	for (size_t i = 0; i < sizeof(str); i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");
	printf("-------mine-----\n");
    ft_memmove(str, str + 2, sizeof(char) * 4);
	for (size_t i = 0; i < sizeof(str); i++)
	{
		printf("%c", str[i]);
	}
    return 0;
}
 