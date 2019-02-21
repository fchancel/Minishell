/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   termcaps.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/21 13:49:40 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/21 19:25:27 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int			initialize_termcap(char **env)
{
	char				*name_term;
	int					ret;


	if ((name_term = get_env(env, "TERM")) == NULL)
	{
		ft_putendl("TERM must be set (see 'env').");
		return (-1) ;
	}
	ret = tgetent(NULL, name_term); //REMPLIS LA STRUCT TERMIOS DES POSSIBILITE DU TERMINAL
	if (ret == -1)
	{
		ft_putendl("Could not acces to the termcap database.");
		return (-1);
	}
	else if (ret == 0)
	{
		ft_putendl("Terminal type is not defined in termcap database (or have too few informations).");
		return (-1);
	}
	return (0);
}

void	 	init_struct_term(void)
{
	struct termios		term;

	if (tcgetatrr(0, term) == -1)   // RECUPERE LES INFORMATION POUR LE TERMINAL
		return ; // ERREUR
	term.c_lflag &= ~(ICANON); // Met le terminal en mode non canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return ; //ERREUR
	return (0);
}

void		reset_struct_term(void)
{
	return;
}

void		applicate_termcaps(char *str);
{
	char 	res;

	res = tgetstr("nd", NULL);
	if (ft_strcmp(str, RIGHT)
		tputs(str,1,fputchar);
	else if (ft_strcmp(str, LEFT)
		ft_putchar('l');
	else if (ft_strcmp(str, DOWN)
		ft_putchar('d');
	else if (ft_strcmp(str, UP)
		ft_putchar('u');
	else if (ft_strcmp(str, HOME)
		ft_putchar('h');
	else if (ft_strcmp(str, END)
		ft_putchar('e');
}

void		go_termcaps(char *str, char **env)
{
	if (initialize_termcap(env) == 0)
	{
		if (init_struct_term() == -1)
			return ; // ERREUR
		applicate_termcaps(str);
	}
	else
	{
		return;
	}
}
