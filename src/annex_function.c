/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   annex_function.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 15:46:03 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/04 18:52:37 by fchancel    ###    #+. /#+    ###.fr     */
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
			count_quote(str, &i, &count, &quote);
		if (!str[i])
			break ;
	}
	return (count);
}

void		count_quote(char *str, int *i, int *count, char *quote)
{
	*quote = str[*i];
	*i += 1;
	*count += 1;
	while (str[*i])
	{
		if (str[*i] == *quote)
		{
			*count += 1;
			break ;
		}
		*i += 1;
	}
}

char	*delete_quote(char *str)
{
	int		i;
	char	quote;

	i = 0;
	while (str[i++])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			quote = str[i];
			str[i] = ' ';
			break ;
		}
	}
	while (str[i])
		i++;
	i--;
	while (i-- >= 0)
	{
		if (str[i] == quote)
		{
			str[i] = ' ';
			break ;
		}
	}
	return (str);
}
