/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:41:09 by seojelee          #+#    #+#             */
/*   Updated: 2023/10/29 12:24:14 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		check_next_line(char *buffer);
char	*get_buffer(int fd, char *buffer);
char	*ft_strjoin(char *s, char *t);
int		ft_strlen(const char *s);
char	*get_line1(char *buffer);
int		ft_strlcpy(char *dst, char *src, int dstsize);
char	*after_buffer(char *buffer);
char	*ft_calloc(int count, int size);
char	*get_buffer_extend(int fd, char *tmp_buffer, char *buffer);
#endif
