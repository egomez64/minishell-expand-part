/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:38:45 by egomez            #+#    #+#             */
/*   Updated: 2024/06/18 17:38:47 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**sep_on_equal(char *s)
{
	char	**new;
	int		i;
	int		y;

	i = 0;
	y = 0;
	new = ft_calloc(3, sizeof(char *));
	while (s[i] && s[i] != '=')
		i++;
	new[0] = ft_substr(s, 0, i);
	i++;
	y = i;
	while (s[i])
		i++;
	new[1] = ft_substr(s, y, i - y);
	return (new);
}

int	export_join(t_env *envi, char *s)
{
	char	**new;
	int		i;

	i = 0;
	new = sep_on_equal(s);
	while (new[0][i] != '+')
		i++;
	new[0][i] = 0;
	while (envi && ft_strcmp(envi->name, new[0]))
		envi = envi->next;
	if (envi)
	{
		envi->val = ft_strjoin(envi->val, new[1]);
		free(new[0]);
		free(new);
	}
	else
	{
		free(new);
		return (1);
	}
	return (0);
}

int	export_append(t_env *envi, char *s)
{
	char	**new_var;
	t_env	*first;

	first = envi;
	new_var = sep_on_equal(s);
	while (first && ft_strcmp(first->name, new_var[0]))
		first = first->next;
	if (first)
		first->val = new_var[1];
	else
	{
		env_add_back(&envi, env_new(new_var[0], new_var[1]));
		free(new_var);
	}
	return (0);
}

int	set_null(t_env *envi, char *s)
{
	t_env	*first;

	first = envi;
	s[ft_strlen(s) - 1] = 0;
	while (first && ft_strcmp(first->name, s))
		first = first->next;
	if (first)
		first->val = NULL;
	else
		env_add_back(&envi, env_new(s, NULL));
	return (0);
}

int	export_add(t_env **envi, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '=')
		i++;
	if (s[ft_strlen(s) - 1] == '=')
		set_null(*envi, s);
	else if (s[i - 1] == '+')
		export_join(*envi, s);
	else
	{
		i = 0;
		if (s[0] >= '0' && s[0] <= '9')
			return (1);
		while (s[i] && s[i] != '=')
		{
			if (is_delimiter(s[i]))
				return (1);
			i++;
		}
		export_append(*envi, s);
	}
	return (0);
}