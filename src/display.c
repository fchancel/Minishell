/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 13:26:47 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/28 15:32:45 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void	prompt(void)
{
	char	pwd[1000];
	int		i;
	char	*prompt;

	i = 0;
	getcwd(pwd, 1000);
	prompt = ft_strrchr(pwd, '/');
	if (ft_strlen(prompt) > 1)
		prompt++;
	ft_putcolor(BOLD_GREEN, "\u279C  ");
	ft_putcolor(BOLD_CYAN, prompt);
	ft_putchar(' ');
}
