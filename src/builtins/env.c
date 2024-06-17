/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maamine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:36:04 by maamine           #+#    #+#             */
/*   Updated: 2024/06/13 15:32:35 by maamine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env(t_env *envi)
{
	while (envi)
	{
		printf("%s=", envi->name);
		if (envi->val)
			printf("%s", envi->val);
		printf("\n");
		envi = envi->next;
	}
	return (0);
}
