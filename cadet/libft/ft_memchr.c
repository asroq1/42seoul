/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:50:57 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/03 17:10:53 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void	*ptr, int value, size_t n)
{
	size_t			idx;
	unsigned char	*tmp;

	idx = 0;
	tmp = ptr;
	while (n != 0)
	{
		if (*tmp == value)
		{
			return (tmp);
		}
		printf("%d\n", tmp);
		tmp++;
		idx++;
		n--;
	}
	return (0);
}

int main() {
  char* pch;
  char str[] = "Example string";
  pch = (char*)ft_memchr(str, 'p', strlen(str));

  if (pch != NULL)
    printf("'p' found at position %d.\n", pch - str + 1);
  else
    printf("'p' not found.\n");

  return 0;
}