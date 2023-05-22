/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:47:23 by gfrancis          #+#    #+#             */
/*   Updated: 2023/05/22 15:32:30 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	while (s[i] != (unsigned char)c && i > 0)
		i--;
	if (i == 0 && s[i] != (unsigned char)c)
	{
		return (0);
	}
	return ((char *)&s[i]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*string;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	string = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!string)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			string[i] = s1[i];
			i++;
		}
	}
	while (s2[j] != '\0')
	{
		string[i++] = s2[j++];
	}
	string[i] = '\0';
	free(s1);
	return (string);
}

char	*ft_substr_divide(char *s, char *substr, int start, int len)
{
	if (start > ft_strlen(s))
	{
		substr = malloc(sizeof(char));
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	else if (len >= ft_strlen(s))
		substr = malloc(ft_strlen(s) - start + 1);
	else
		substr = malloc(len + 1);
	if (!substr)
		free(substr);
	return (substr);
}

char	*ft_substr(char *str, int start, int len, int do_free)
{
	char	*substr;
	int		i;
	int		j;

	substr = NULL;
	i = -1;
	j = 0;
	substr = ft_substr_divide(str, substr, start, len);
	while (str[++i] != '\0')
	{
		if (i >= start && j < len)
			substr[j++] = str[i];
	}
	substr[j] = '\0';
	if (do_free)
		free(str);
	return (substr);
}
