/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strplit.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 20:49:35 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 17:39:01 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *s, char c)
{
	int c_word;

	c_word = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			c_word++;
		s++;
	}
	return (c_word);
}

static int		ft_count_letter(char const *s, char c)
{
	int c_letter;

	c_letter = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		c_letter++;
	}
	return (c_letter);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		word;
	int		letter;

	if (!s || !c)
		return (NULL);
	word = ft_count_word(s, c);
	letter = 0;
	if (!(array = (char **)malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	while (word--)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(array[letter] = ft_strsub(s, 0, ft_count_letter(s, c))))
		{
			ft_free_2tab((void**)array);
			return (NULL);
		}
		s = s + ft_count_letter(s, c);
		letter++;
	}
	array[letter] = NULL;
	return (array);
}
