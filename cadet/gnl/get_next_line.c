/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:21:17 by hyunjung          #+#    #+#             */
/*   Updated: 2022/01/05 16:07:09 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_left_lstr(char *lstr)
{
	
}

char	*ft_split_lstr(char *lstr)
{
	
}

char	*ft_get_lstr(int fd, char *lstr)
{
    
}

char	*get_next_line(int fd)
{	
	static char	*lstr;
	char		*str;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 0)
	{
		return (-1);
	}
    /* \n를 만나거나 eof가 나오기 전까지 읽고 lstr에 저장 */
	lstr = ft_get_lstr(fd, lstr);
	if (lstr == 0)
	{
		return (0);
	}
    // \n 이전의 문자열을 str에 저장
	str = ft_split_lstr(lstr);
    // lstr에  str이후의 문자를 남기기
	lstr = ft_left_lstr(lstr);
	return (str);
}
