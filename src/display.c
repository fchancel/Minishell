/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 13:26:47 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/14 14:40:04 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void	prompt(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD", 3) == 0)
		{
			env[i] = ft_strrchr(env[i], '/');
			env[i] += 1;
			ft_putcolor(BOLD_GREEN, "\u279C  ");
			ft_putcolor(BOLD_CYAN, env[i]);
			ft_putchar(' ');
			break;
		}
		i++;
	}
}
