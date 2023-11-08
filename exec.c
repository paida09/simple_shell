#include "shell.h"

/**
 * exec_func - Executes a command.
 * @myvars: Pointer.
 *
 * Return: 0 on success, 1 on failure.
 */
int exec_func(vars_t *myvars)
{
	struct stat buff;
	pid_t l_pid;

	if (stat(myvars->av[0], &buff) != 0)
	{
		error_print(myvars, ": not found\n");
		myvars->status = 127;
		return (0);
	}
	if (access(myvars->av[0], X_OK) != 0)
	{
		error_print(myvars, ": Permission denied\n");
		myvars->status = 126;
		return (0);
	}

	l_pid = fork();
	if (l_pid == -1)
	{
		error_print(myvars, NULL);
		return (1);
	}
	if (l_pid == 0)
	{
		if (execve(myvars->av[0], myvars->av, myvars->env) == -1)
			error_print(myvars, NULL);
	}
	else
	{
		wait(&myvars->status);
		if (WIFEXITED(myvars->status))
			myvars->status = WEXITSTATUS(myvars->status);
		else if (WIFSIGNALED(myvars->status) && WTERMSIG(myvars->status) == SIGINT)
		{
			myvars->status = 130;
		}
	}

	return (0);
}
