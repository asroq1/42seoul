/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:14:11 by hyunjung          #+#    #+#             */
/*   Updated: 2021/11/19 12:44:07 by hyunjung         ###   ########.fr       */
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
		printf("first if\n");
		while (idx < size)
		{
			*new_dest++ = *new_src++;
			idx++;
		}
	}
	else
	{
		printf("sec if\n");
		new_dest = dest + (size - 1);
		new_src = src + (size - 1);
		while (idx < size)
		{
			new_dest[size - 1] = new_src[size - 1];
			idx++;
		}
	}
	return (dest);
}


int main(void)
{
     char array[10];
        
        memset(array, 0, sizeof(array));
        strcpy(array, "test");
        
        printf("original : %s\n", array);
        
        // memmove(array, array+2, strlen("test"));
        // printf("after memmove : %s\n", array);

        ft_memmove(array, array+2, strlen("test"));
        printf("my memmove : %s\n", array);
        
        return 0;
    return 0;
}
 