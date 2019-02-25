/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_linked_list.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/25 14:33:44 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/25 14:39:19 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

t_cmd		*initialize_cmd(void)
{
	t_cmd		*cmd;

	if ((cmd = (t_cmd*)malloc(sizeof(t_cmd))) == NULL)
		display_error_exit("error malloc cmd in initialize_cmd");
	cmd->tab_cmd = NULL;
	cmd->next = NULL;
	return (cmd);
}
