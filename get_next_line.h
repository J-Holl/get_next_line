/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:39:04 by jholl             #+#    #+#             */
/*   Updated: 2021/03/02 14:39:08 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

size_t		ft_strlen(const char *s);
int			str_free(char *s);
int			get_next_line(int fd, char **line);
char		*ft_strjoin_free(char *s1, char *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strdup(const char *s);

#endif
