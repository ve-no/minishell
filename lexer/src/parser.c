#include "include/parser.h"
#include "include/lexer.h"

// char	*get_path(char *cmd, char **env)
// {
// 	char	*path;
// 	char	*dir;
// 	char	*bin;
// 	int		i;

// 	i = 0;
// 	while (env[i] && str_ncmp(env[i], "PATH=", 5))
// 		i++;
// 	if (!env[i])
// 		return (cmd);
// 	path = env[i] + 5;
// 	while (path && str_ichr(path, ':') > -1)
// 	{
// 		dir = str_ndup(path, str_ichr(path, ':'));
// 		bin = join_path(dir, cmd);
// 		free(dir);
// 		if (access(bin, F_OK) == 0)
// 			return (bin);
// 		free(bin);
// 		path += str_ichr(path, ':') + 1;
// 	}
// 	return (cmd);
// }

// t_prompt	parser()
// {
// 	lexer_T* lexer = init_lexer(readline("minishell$ "));
// 	token_T* token = (void*)0;

// 	while ((token = lexer_get_next_token(lexer)) != (void*)0)
// 	{
// 		if (token->value[0] == '$' || token->value[0] == '~')
// 			printf("TOKEN(%d, '%s')\n", token->type, expand_variable(token->value));
// 		else
// 			printf("TOKEN(%d, '%s')\n", token->type, token->value);
// 	}
// }

static t_list	*list_init(void)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->full_cmd = NULL;
	node->full_path = NULL;
	node->infile = STDIN;
	node->outfile = STDOUT;
	return (node);
}
static t_list	*get_params(t_list *node, token_T *a, int *i)
{
	if (a[0][*i])
	{
		if (a[0][*i][0] == '>' && a[0][*i + 1] && a[0][*i + 1][0] == '>')
			node = get_outfile2(node, a[1], i);
		else if (a[0][*i][0] == '>')
			node = get_outfile1(node, a[1], i);
		else if (a[0][*i][0] == '<' && a[0][*i + 1] && \
			a[0][*i + 1][0] == '<')
			node = get_infile2(node, a[1], i);
		else if (a[0][*i][0] == '<')
			node = get_infile1(node, a[1], i);
		else if (a[0][*i][0] != '|')
			node->full_cmd = ft_extend_arr(node->full_cmd, a[1][*i]);
		else
		{
			mini_perror(PIPENDERR, NULL, 2);
			*i = -2;
		}
		return (node);
	}
	mini_perror(PIPENDERR, NULL, 2);
	*i = -2;
	return (node);
}
