/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 21:32:59 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 12:29:50 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10
# define FREE 0
# define FD_FOR_FREE 0
# define LINE_FOR_FREE NULL
# define NORMAL_USE 1
# include "libft.h"

int					get_next_line(const int fd, char **line, int error);

#endif
