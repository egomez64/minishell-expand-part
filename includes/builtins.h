/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maamine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:59:40 by maamine           #+#    #+#             */
/*   Updated: 2024/06/13 10:12:43 by maamine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <linux/limits.h>

bool	is_builtins(const char	*s);
void	handle_builtins(t_cmd	*cmd, t_env **envi);
int		pwd(void);
int		env(t_env *envi);
int		export(t_env **envi, char *s);

#endif
