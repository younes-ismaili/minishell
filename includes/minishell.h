/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:30:46 by souchen           #+#    #+#             */
/*   Updated: 2022/08/01 22:21:59 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include </Users/yismaili/goinfre/.brew/opt/readline/include/readline/readline.h>
# include </Users/yismaili/goinfre/.brew/opt/readline/include/readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
#include <dirent.h>


# define Double_Quote '\"'
# define QUOTE '\''
# define D_QUOTE_S "\""
# define QUOTE_S "\'"
# define WHITE "\001\033[0m\002"
# define GREEN "\001\033[1;32m\002"
# define RED "\033[0;31m"

int glob_var;
int g_status;

typedef struct s_env
{
	char	**env;
	int		len;
	char	**tmp_var;
	char	**tmp_con;
	int		position;;
}			t_env;
typedef struct s_divise
{
	int		number_command;
	int		initial;
	int		len;
	int		quote;
	int		pipe;
}			t_divise;

typedef struct s_arg
{
	char	*all_cmd;
	char	*to_exec;
	char    *txt_toprint;
	char	quote;
	char	*seconde;
	char	*first;
	int		i;
	int		init;
	int		len;
	int		position;
}			t_arg;
int glob_var;
typedef struct s_struct
{
	int	builtin_exist;
	int		last_redir;
	int		output_fd;
	int		input_fd;
	int		cmp;
	char	*line_commande;
	char	*commande_tape;
	char	*home;
		pid_t	pid;
	char	*commands[600000];
	char	**arguments;
	char	**cmd_splited;
	int i;
	int len;
	///char	**path;
	t_env	env_aux;
	t_env	env;
	t_divise divise;
	t_arg	arg;
}			t_struct;

int		builtin_exist(t_struct *shell);
void	run_builtin(t_struct *shell);
int		count_len_env(t_struct *shell);
void	ft_exit(t_struct *shell);
void	free_line(char *line_read);
void	free1(char **array);
void	free2(char **array);
void	ft_unset(t_struct *shell);
void	remove_env(t_struct *shell);
void	print_welcome(void);
char	*get_current_dir(void);
char	*create_prompt(void);
void	run_commands(t_struct *shell);
void	run_commande_next(t_struct *shell);
void	fun_redirection(t_struct *shell);
void	execution(t_struct *shell);
void	divise_commande(t_struct *shell, char *in);
void	arguments_func(t_struct *shell);
int		argument_find_char(char *string, char needle);
void	free_arg(t_arg *arg);
void	finish_put_arg(t_struct *shell, t_arg *arg);
void 	init_divise_struct(t_struct *shell);
t_arg	*init_arg();
void 	ft_env(t_struct *shell);
void 	ft_export(t_struct *shell);
bool 	there_is_home(t_struct *shell);
int 	ft_cd(t_struct *shell);
void 	ft_pwd();
void 	ft_echo(t_struct *shell);
int 	init_echo(t_struct *shell, int n);
void 	print_echo(t_struct *shell,char* shell_print);
void 	verify_if_env_exists(t_struct *shell, char **env_aux);
void 	export_to_env(t_struct *shell, char *new_elem_tab1, char *new_elem_tab2);
void 	pipe_next(t_struct *shell, int i, char *command);
void 	inredirection(t_struct *shell);
void 	outredirection(t_struct *shell);
void 	next_run_commands(t_struct *shell);
void 	next(t_struct *shell, char*commande_read);
char 	*execute_cmd(t_struct *shell, char **path);
void 	output_input(t_struct *shell);
void 	check_to_execute(t_struct *shell);
void    sig_handler(int signum);
void 	cmd_not_found(char *cmd);
int 	check_export(t_struct *export);
int 	ft_search(t_struct *env, char *var);
int 	malloc_env_tmp(t_struct *shell);
char	*find_env_tmp(t_struct *shell, char *search);
int		commande_tape(t_struct	*shell, int *size);
int		malloc_env_aux_tmp(t_struct *shell);
void	ft_die(char *str);
int		create_env_tmp(t_struct *shell, char **my_env);
int  	start_create_env(t_struct *shell);
void	ft_die_malloc(char *str);
void	ft_check_env(char **env);
void	ft_free_env(char **env);
void	ft_free_cmd(char **cmd);
int		line_empty(char *input);
void	ft_not_found(char *dir);
char	*ft_split_cmd(char *cmd);
int		ft_serch_in_env(t_struct *env, char	*var, char *con);
void	func(t_struct *shell,int i, int status);
void	ft_free(t_struct *shell);
void	get_exit_code(int status);
char	**get_path(t_struct *ptr);
void	next_execute_cmd(char **cmd_path);
void	process_shild_execute(char **path, t_struct *shell);
void	printf_cmd_not_f(t_struct *shell);
void	signals();
void	restore_prompt(int sig);
void	ctrl_c(int sig);
void	back_slash(int sig);
int		ft_cd_tool(t_struct *shell);
char	*ft_oldpath(t_struct *shell);
void	ft_change_dir(t_struct *shell, char *chpath);
int		ft_check_cd(t_struct *shell);
void	replace_oldpwd(t_struct *env);
void	replace_pwd(t_struct *env);
void	ft_echo_tool(t_struct *shell, char *echo_print);
char	**ft_swap_env(char	**dup_env);
void	ft_error_eprt(char *cmd);
void	ft_export_tool(t_struct *shell);
void	ft_print_export(char **export, t_struct	*shell);
char	**ft_dup_env(t_struct *shell);
void	sort_env(t_struct *env);
void	ft_error_fork(void);

#endif
