/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_env.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 14:50:02 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/05 14:23:34 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void		builtin_env(char **cmd, t_env *my_env)
{
	if (!cmd[1])
		print_env(my_env);
	else if (ft_strcmp(cmd[1], "-i"))
	{
		ft_putchar('\n');
	}
}

void		print_env(t_env *my_env)
{
	int		i;

	i = 0;
	while (my_env->env[i])
	{
		ft_putstr(my_env->env[i]);
		ft_putchar('\n');
		i++;
	}
}
