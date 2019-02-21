/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 18:18:09 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/21 19:28:34 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
 **		Recupere dans line la commande de l'entrer standard
 */

char		*ft_read(char **env)
{
	char	buf[BUF_SIZE + 1];
	int		ret;
	char	*line;
	char	*tamp;

	tamp = NULL;
	line = NULL;
	ret = 0;
	while ((ret = read(0, &buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		if (is_caps(buf) == 1)
			go_termcaps(buf, env);
		else
		{
			tamp = line;
			line = ft_strjoin(tamp, buf);
			if (tamp)
				free(tamp);
			if (char_search(buf, '\n') == 0)
				break ;
		}
	}
	return (line);
}

/*
 **		Creer la ligne de commande avec la gestion des quotes
 */

t_cmd		*get_line(char **env)
{
	char		*line;
	int			bol;
	int			i;
	char		*tamp;
	t_cmd		*cmd;

	i = 0;
	bol = 0;
	while (bol == 0)
	{
		line = ft_read(env);
		while ((ft_twin_quote(line) % 2) != 0)
		{
			ft_putstr("dquote> ");
			tamp = line;
			line = ft_strjoin(line, ft_read(env));
			free(tamp);
		}
		bol = 1;
	}
	cmd = create_cmd(line);
	free(line);
	return (cmd);
}

t_cmd		*initialize_cmd(void)
{
	t_cmd		*cmd;

	if ((cmd = (t_cmd*)malloc(sizeof(t_cmd))) == NULL)
		display_error_exit("error malloc cmd in initialize_cmd");
	cmd->tab_cmd = NULL;
	cmd->next = NULL;
	return (cmd);
}

t_cmd		*create_cmd(char *line)
{
	char	**tab;
	t_cmd	*cmd;
	t_cmd	*n_cmd;
	t_cmd	*start;
	int	i;

	i = 0;
	tab = create_tab(line);
	cmd = fill_tab_cmd(tab[i]);
	start = cmd;
	i++;
	while (tab[i])
	{
		n_cmd = fill_tab_cmd(tab[i]);
		cmd->next = n_cmd;
		cmd = cmd->next;
		i++;
	}
	return (start);

}

t_cmd		*fill_tab_cmd(char *line)
{
	int		i;
	t_cmd	*cmd;

	i = 0;
	cmd = initialize_cmd();
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = ' ';
		i++;
	}
	cmd->tab_cmd = ft_strsplit(line, ' ');
	return (cmd);
}

char		**create_tab(char *line)
{
	char		**tab;
	int		i;

	i = 0;
	if ((tab = (char**)malloc(sizeof(char *) *
					ft_count_char(';', line) + 2)) == NULL)
		display_error_exit("error malloc tab in create_cmd");
	if (ft_strchr(line, ';') != NULL)
		tab = ft_strsplit(line, ';');
	else
	{
		if ((tab = (char **)malloc(sizeof(char *) * 2)) == NULL)
			display_error_exit("error malloc tab in create_cmd whitout';'");
		tab[0] = ft_strdup(line);
	}
	return (tab);
}
