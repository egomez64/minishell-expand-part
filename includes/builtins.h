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
int		export_add(t_env **envi, char *s);
int		export(t_env *envi);
void	print_export(char **new_env);
void	free_env(char **new_env);
void	bubble_sort(char **new_env);
int		export_join(t_env *envi, char *s);
int		export_append(t_env *envi, char *s);
int		set_null(t_env *envi, char *s);

#endif
