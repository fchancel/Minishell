/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   annex_function.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 15:46:03 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 16:30:17 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int			char_search(char *str, char c)
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

int			ft_twin_quote(char *str)
{
	int		i;
	int		count;
	char	quote;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i];
			i++;
			count++;
			while (str[i])
			{
				if (str[i] == quote)
				{
					count++;
					break ;
				}
				i++;
			}
		}
	}
	return (count);
}
