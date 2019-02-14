/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 18:18:09 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/14 16:11:53 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int		char_search(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (-1);
}

char	*ft_read(void)
{
	char	buf[BUF_SIZE + 1];
	int		ret;
	char	*line;
	char	*tamp;

	tamp = NULL;
	line = NULL;
	ret = 0;
	while ((ret = read(0, &buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		tamp = line;
		line = ft_strjoin(tamp, buf);
		if (tamp)
			free(tamp);
		if (char_search(buf, '\n') == 0)
			break;
	}
	return (line);
}
