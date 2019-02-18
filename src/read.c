/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 18:18:09 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 19:30:53 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
 **		Recupere dans line la commande de l'entrer standard
 */

char		*ft_read(void)
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
		tamp = line;
		line = ft_strjoin(tamp, buf);
		if (tamp)
			free(tamp);
		if (char_search(buf, '\n') == 0)
			break ;
	}
	return (line);
}

/*
 **		Creer la ligne de commande avec la gestion des quotes
 */

t_cmd		*get_line(void)
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
		line = ft_read();
		while ((ft_twin_quote(line) % 2) != 0)
		{
			ft_putstr("dquote> ");
			tamp = line;
			line = ft_strjoin(line, ft_read());
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

t_cmd		*fill_tab_cmd(char **tab)
{
	int		i;
	int		j;
	t_cmd	*cmd;
	t_cmd	*start;

	i = 0;
	j = 0;
	cmd = initialize_cmd();
	start = cmd;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (tab[i][j] == '\n')
				tab[i][j] = ' ';
			j++;
		}
		j = 0;
		cmd->tab_cmd = ft_strsplit(tab[i], ' ');
		cmd->next = initialize_cmd();
		cmd = cmd->next;
		i++;
	}
	return (start);
}

t_cmd		fill_tab_cmd()
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((cmd->tab_cmd = (char **)malloc(sizeof(char *) * 3)) == NULL)
		display_error_exit("error malloc cmd->tab_cmd in |||||||||||");
	while (line)
	{
		if (line[i] == ' ' || line[i] == '\0')
		{
			cmd->tab_cmd[0] = ft_strsub(line, 0, i);
			break;
		}
		i++;
	}
	cmd->tab_cmd[1] = ft_strsub(line, i, ft_strlen(line) - i);
	cmd->tab_cmd[2] = '\0';
	return (cmd);
}

/*
 **		Creer une liste chainee ou chaque maillon correspond a une commande stocke dans un double tableau
 **		tab_cmd[0] = le nom de la commande, la suite les arguments
 */

t_cmd		*create_cmd(char *line)
{
	t_cmd		*cmd;
	char		**tab;
	int			i;

	i = 0;
	cmd = initialize_cmd();
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
	cmd = fill_tab_cmd(tab);
	return (cmd);
}
