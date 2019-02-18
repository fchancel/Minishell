/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_char.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 14:44:08 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 15:02:09 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_count_char(char c, char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (!str)
		return (count);
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
