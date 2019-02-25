/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 13:26:47 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/25 16:12:11 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void	prompt()
{
	char	*pwd;
	char	*tmp;


	pwd = ft_strnew(1000);
	tmp = pwd;
	getcwd(pwd, 1000);
	pwd  = ft_strrchr(pwd, '/');
	pwd++;
	ft_putcolor(BOLD_GREEN, "\u279C  ");
	ft_putcolor(BOLD_CYAN, pwd);
	ft_putchar(' ');
	//free(tmp);
}
