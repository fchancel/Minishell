/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 18:18:09 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 11:24:46 by fchancel    ###    #+. /#+    ###.fr     */
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
	int		test;

	tamp = NULL;
	line = NULL;
	ret = 0;
	test = 0;
	while ((ret = read(0, &buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		tamp = line;
		line = ft_strjoin(line, buf);
		if (tamp)
			free(tamp);
		if (char_search(buf, '\n') == 0)
			break;
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
	char		*tmp2;
	char		*tamp;
	t_cmd		*cmd;

	bol = 0;
	while (bol == 0)
	{
		line = ft_read();
		while ((ft_twin_quote(line) % 2) != 0)
		{
			ft_putstr("dquote> ");
			tamp = line;
			tmp2 = ft_read();
			line = ft_strjoin(line, tmp2);
			free(tmp2);
			free(tamp);
		}
		bol = 1;
	}
	cmd = create_cmd(line);
	free(line);
	return (cmd);
}

t_cmd		*create_cmd(char *line)
{
	char	**tab;
	t_cmd	*cmd;
	t_cmd	*start;
	int	i;

	i = 0;
	tab = create_tab(line);
	cmd = fill_tab_cmd(tab[i]);
	start = cmd;
	i++;
	while (tab[i])
	{
		cmd->next = fill_tab_cmd(tab[i]);
		cmd = cmd->next;
		i++;
	}
	ft_free_2tab((void*)tab);
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
	if (ft_strchr(line, ';') != NULL)
		tab = ft_strsplit(line, ';');
	else
	{
		if ((tab = (char **)ft_memalloc(sizeof(char *) * 2)) == NULL)
			display_error_exit("error malloc tab in create_cmd whitout';'");
		tab[0] = ft_strdup(line);
	}
	return (tab);
}
