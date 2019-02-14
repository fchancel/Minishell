/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 21:16:18 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 17:36:45 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_str(int fd, char **str_finish)
{
	char	*tamp;
	int		ret;
	char	*buf;

	ret = 0;
	if (!(tamp = ft_strnew(0)))
		return (-1);
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		if (!(*str_finish = ft_strnjoin(tamp, buf, ret)))
			return (-1);
		free(tamp);
		if (!(tamp = ft_strdup(*str_finish)))
			return (-1);
		free(*str_finish);
	}
	free(buf);
	if (!(*str_finish = ft_strdup(tamp)))
		return (-1);
	free(tamp);
	return (1);
}

int			get_line(char **str, char **line)
{
	int		i;
	char	*tamp;

	i = 0;
	if (ft_strlen(*str) == 0)
		return (0);
	if (!(tamp = ft_strdup(*str)))
		return (-1);
	ft_strdel(str);
	while (tamp[i] != '\n' && tamp[i] != '\0')
		i++;
	if (!(*line = ft_strsub(tamp, 0, i)))
		return (-1);
	if (!(*str = ft_strsub(tamp, i + 1, ft_strlen(tamp) - i)))
		return (-1);
	ft_strdel(&tamp);
	return (1);
}

int			get_next_line(const int fd, char **line, int error)
{
	int				ret;
	static	char	*str_finish;

	if (error == NORMAL_USE)
	{
		if (fd < 0 || !line)
			return (-1);
		ret = 0;
		if (!str_finish)
		{
			if (get_str(fd, &str_finish) < 0)
				return (-1);
		}
		if ((ret = get_line(&str_finish, line)) == 0)
			ft_strdel(&str_finish);
		return (ret);
	}
	else if (error == FREE)
		ft_strdel(&str_finish);
	else
		ft_putendl("Please, send a valid INT ERROR");
	return (0);
}
