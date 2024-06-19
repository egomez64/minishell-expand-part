/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:25:14 by egomez            #+#    #+#             */
/*   Updated: 2024/06/17 15:25:16 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_builtins(const char	*s)
{
	if (!ft_strcmp(s, "echo") || !ft_strcmp(s, "cd") || !ft_strcmp(s, "pwd") \
		|| !ft_strcmp(s, "export") || !ft_strcmp(s, "env") || !ft_strcmp(s, "unset") \
		|| !ft_strcmp(s, "exit"))
		return (true);
	return (false);
}

void	handle_builtins(t_cmd	*cmd, t_env **envi)
{
	if (cmd->arguments->content && !ft_strcmp(cmd->arguments->content, "pwd"))
		pwd();
	else if (cmd->arguments->content && !ft_strcmp(cmd->arguments->content, "env"))
		env(*envi);
	else if (cmd->arguments->content && !ft_strcmp(cmd->arguments->content, "export"))
	{
		if (cmd->arguments->next)
		{
			cmd->arguments = cmd->arguments->next;
			while (cmd->arguments && ft_strchr(cmd->arguments->content, '='))
			{
				export_add(envi, cmd->arguments->content);
				cmd->arguments = cmd->arguments->next;
			}
		}
		else
			export(*envi);
	}
	else if (cmd->arguments->next && !ft_strcmp(cmd->arguments->content, "unset"))
		unset(*envi, cmd->arguments->next->content);
}
