/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:18:57 by kijsong           #+#    #+#             */
/*   Updated: 2023/02/16 19:37:43 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	exit_minishell(t_token *tokens, t_env *env)
{
	int		argc;
	char	**argv;

	argc = find_argv_size(tokens);
	argv = make_argv(tokens);
	unlink("/tmp/.heredoc");
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (argc > 2 && is_number(argv[1]))
	{
		ft_free(argv);
		builtin_error(env, "exit", NULL, "too many arguments");
		env->exit_code = EXIT_FAILURE;
		return ;
	}
	if (argc == 1)
		env->exit_code = EXIT_SUCCESS;
	else if (argc == 2 && is_number(argv[1]))
		env->exit_code = ft_atoi(argv[1]) & 255;
	else
	{
		builtin_error(env, "exit", argv[1], "numeric argument required");
		env->exit_code = 255;
	}
	exit(env->exit_code);
}

void	execute_command(char *input, t_exec *exec)
{
	int		heredoc_res;
	t_token	*tokens;
	t_anode	*ast;

	safe_signal(SIGINT, SIG_IGN);
	tokens = tokenize(input, exec->env);
	heredoc_res = 0;
	if (has_heredoc(tokens))
		heredoc_res = heredoc(tokens, exec);
	if (heredoc_res != -1)
	{
		ast = list_to_ast(tokens);
		if (!has_pipe(tokens) && is_exit(tokens->head->next))
			exit_minishell(tokens, exec->env);
		else
			exec->env->exit_code = ast_preorder(ast, exec);
		clear_ast(ast);
	}
	else
		clear_token(tokens);
	clear_heredocs(exec);
}
