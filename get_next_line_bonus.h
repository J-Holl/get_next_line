/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:36:48 by jholl             #+#    #+#             */
/*   Updated: 2021/03/02 14:40:05 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct		s_list
{
	int				save_fd;
	char			content_read[BUFFER_SIZE + 1];
	struct s_list	*next;
}					t_list;

int					line_len_free(char *current_line, char *s, char *to_free);
void				ft_lst_free(t_list *to_free);
int					ft_lst(t_list **lst, t_list *to_del, int rtrn);
void				ft_lstadd_back(t_list **alst, t_list *new);
int					read_next_buff(int fd, char **line, t_list *temp,
					t_list **lst);
int					get_next_line(int fd, char **line);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

#endif
