/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:42:17 by jholl             #+#    #+#             */
/*   Updated: 2021/03/02 14:43:44 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin_free(char *s1, char *s2)
{
	char	*new_s;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
	{
		if (!s1)
			return (ft_strdup(s2));
		else if (!s2)
			return (ft_strdup(s1));
	}
	new_s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new_s)
	{
		str_free(s1);
		return (NULL);
	}
	*new_s = '\0';
	ft_strlcat(new_s, s1, (ft_strlen(s1) + 1));
	ft_strlcat(new_s, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	str_free(s1);
	return (new_s);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

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

char		*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;

	if (start >= ft_strlen(s))
		return (ft_strdup("\0"));
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	*new_str = '\0';
	if (!s)
		return (new_str);
	ft_strlcat(new_str, s + start, len + 1);
	return (new_str);
}
