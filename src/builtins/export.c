/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maamine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:36:25 by maamine           #+#    #+#             */
/*   Updated: 2024/06/13 15:32:19 by maamine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	export(t_env **envi, char *s)
{
	char	**new_var;
	int		i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	if (s[i] != '=')
		return (1);
	new_var = ft_split(s, '=');
	env_add_back(envi, env_new(new_var[0], new_var[1]));
	free_split(new_var);
	return (0);
}
