/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strspn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:29:20 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/23 22:38:00 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <string.h>
int	ft_strspn(const char *s, const char *accept){
	
	int i = 0;
	int j = 0;
	
	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{	
			if (s[i] != accept[j])
			{
			
				return j;
			}
		
			j++;
		}
		i++;	
	}
	printf("%ld", sizeof(s));
	return sizeof(s);	
}

int main()
{ 
char string[] = "HLELOP";
	char strCharset[] = "HEL8";
	
	printf("origin : %ld\n", strspn(string,strCharset));
	
	printf("%d",ft_strspn(string, strCharset));
}