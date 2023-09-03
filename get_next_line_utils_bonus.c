/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:39:30 by jholl             #+#    #+#             */
/*   Updated: 2021/03/02 14:40:21 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int			ft_lst(t_list **lst, t_list *to_del, int rtrn)
{
	t_list	*temp;
	t_list	*temp1;

	temp = *lst;
	if (!to_del)
		return (rtrn);
	if (temp == to_del)
	{
		temp1 = temp->next;
		ft_lst_free(temp);
		*lst = temp1;
		return (rtrn);
	}
	while (!(temp->next == to_del))
		temp = temp->next;
	temp1 = to_del->next;
	ft_lst_free(to_del);
	temp->next = temp1;
	return (rtrn);
}

void		ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *temp;

	if (!alst || !new)
		return ;
	temp = *alst;
	if (*alst)
	{
		while ((*alst)->next)
			*alst = (*alst)->next;
		(*alst)->next = new;
		*alst = temp;
	}
	else
		*alst = new;
}

char		*ft_strjoin_free(char *s1, char *s2)
{
	char	*new_s;
	size_t	size_s1;
	size_t	size_s2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	else if (!s2)
		return (s1);
	size_s1 = line_len_free(NULL, s1, NULL);
	size_s2 = line_len_free(NULL, s2, NULL);
	if (!(new_s = (char *)malloc((size_s1 + size_s2 + 1) * sizeof(char))))
		line_len_free(NULL, NULL, s1);
	if (!new_s)
		return (NULL);
	*new_s = '\0';
	ft_strlcat(new_s, s1, (size_s1 + 1));
	ft_strlcat(new_s, s2, (size_s1 + size_s2 + 1));
	line_len_free(NULL, NULL, s1);
	return (new_s);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != size)
		dst[i + j] = '\0';
	j = 0;
	while (src[j])
		j++;
	return (i + j);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	size_s;

	size_s = 0;
	while (s[size_s])
		size_s++;
	if (start >= size_s)
		len = 0;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	*new_str = '\0';
	if (!s)
		return (new_str);
	ft_strlcat(new_str, s + start, len + 1);
	return (new_str);
}
