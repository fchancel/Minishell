/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 13:26:47 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 17:41:41 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void	prompt(char *pwd)
{
	pwd  = ft_strrchr(pwd, '/');
	pwd++;
	ft_putcolor(BOLD_GREEN, "\u279C  ");
	ft_putcolor(BOLD_CYAN, pwd);
	ft_putchar(' ');
}
