/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:36:32 by jholl             #+#    #+#             */
/*   Updated: 2021/03/02 14:36:39 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void				ft_lst_free(t_list *to_free)
{
	if (to_free)
	{
		free(to_free);
		to_free = NULL;
	}
}

int					line_len_free(char *current_line, char *s, char *to_free)
{
	size_t i;

	if (to_free)
	{
		free(to_free);
		to_free = NULL;
		return (0);
	}
	if (s)
	{
		i = 0;
		while (s[i])
			i++;
		return (i);
	}
	while (*current_line)
	{
		if (*current_line == '\n')
			return (1);
		current_line++;
	}
	return (0);
}

char				*cut_current_line(char *current_line, char *content_read)
{
	int				i;
	char			*temp;
	int				j;

	i = 0;
	while (content_read[i] && content_read[i] != '\n')
		i++;
	if (content_read[i])
		i++;
	j = 0;
	while (content_read[i])
	{
		content_read[j] = content_read[i];
		i++;
		j++;
	}
	content_read[j] = '\0';
	i = 0;
	while (current_line[i] && current_line[i] != '\n')
		i++;
	temp = ft_substr(current_line, 0, i);
	line_len_free(NULL, NULL, current_line);
	if (!temp)
		return (NULL);
	return (temp);
}

int					read_next_buff(int fd, char **line, t_list *temp,
					t_list **lst)
{
	int				val_read;
	char			*current_line;

	current_line = NULL;
	if (!(current_line = ft_substr(temp->content_read, 0, BUFFER_SIZE)))
		return (ft_lst(lst, temp, -1));
	val_read = 1;
	while (!line_len_free(current_line, NULL, NULL) && val_read > 0)
	{
		if ((val_read = read(fd, temp->content_read, BUFFER_SIZE)) < 0)
			line_len_free(NULL, NULL, current_line);
		if (val_read < 0)
			return (ft_lst(lst, temp, -1));
		temp->content_read[val_read] = '\0';
		if (!(current_line = ft_strjoin_free(current_line, temp->content_read)))
			return (ft_lst(lst, temp, -1));
	}
	if (!(*line = cut_current_line(current_line, temp->content_read)))
		return (ft_lst(lst, temp, -1));
	if (val_read == 0)
		return (ft_lst(lst, temp, 0));
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static t_list	*lst_read;
	t_list			*temp;
	int				play;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	play = 1;
	temp = lst_read;
	while (temp && play)
	{
		if (temp->save_fd == fd)
			play = 0;
		else
			temp = temp->next;
	}
	if (play)
	{
		if (!(temp = (t_list *)malloc(sizeof(t_list) * 1)))
			return (-1);
		temp->save_fd = fd;
		temp->content_read[0] = '\0';
		temp->next = NULL;
		ft_lstadd_back(&lst_read, temp);
	}
	return (read_next_buff(fd, line, temp, &lst_read));
}
