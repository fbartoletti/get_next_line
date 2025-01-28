/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:09:06 by marvin            #+#    #+#             */
/*   Updated: 2024/04/03 12:09:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_stop(char *all, int c)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)&c; // Cast a char* e otteniamo l'indirizzo di c
	if (all == NULL)
		return (NULL);
	while (all[i] != '\0')
	{
		if (all[i] == *s) // Dereferenziamo s per ottenere il valore di c
			return ((char *)all + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *all, char *buf)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!all)
	{
		all = (char *)malloc(sizeof(char) * 1);
		all[0] = '\0';
	}
	if (!all || !buf)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ((ft_strlen(all) + ft_strlen(buf) + 1)));
	if (!str)
		return (NULL);
	if (all)
		while (all[++i])
			str[i] = all[i];
	while (buf[j])
		str[i++] = buf[j++];
	str[ft_strlen(all) + ft_strlen(buf)] = '\0';
	// Aggiungi una condizione per evitare di liberare all se è la stessa stringa passata a get_next_line
	if (all != buf) // Assicurati che all e buf non siano la stessa stringa
		free(all);
	return (str);
}

char	*ft_take_line(char *all)
{
	char	*str;
	int		i;

	i = 0;
	if (!*all)
		return (NULL);
	while (all[i] && all[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (all[i] && all[i] != '\n')
	{
		str[i] = all[i];
		i++;
	}
	if (all[i] == '\n')
	{
		str[i] = all[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_save(char *all)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (all[i] && all[i] != '\n')
		i++;
	if (!all[i])
	{
		free(all);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(all) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (all[i])
		str[j++] = all[i++];
	str[j] = '\0';
	free(all);
	return (str);
}
