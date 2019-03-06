/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:00:18 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/06 13:33:34 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int		main(int ac, char **av, char **env)
{
	t_env	*my_env;

	(void)ac;
	(void)av;
	my_env = dup_env(env);
	loop(my_env);
	return (0);
}
