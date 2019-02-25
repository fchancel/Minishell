/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_error.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 10:20:15 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/25 15:00:15 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void		display_error_exit(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	exit(0);
}

void		no_command(char *str)
{
	ft_putstr("minishell: command not found: ");
	ft_putendl(str);
}
