#include "shell.h"

/**
 * path_exe - ...
 * @command: ...
 * @myvars: ...
 *
 * Return: 0 on success, 1 on failure.
 */
int path_exe(char *command, vars_t *myvars)
{
	pid_t l_pid;

	if (access(command, X_OK) != 0)
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
		if (execve(command, myvars->av, myvars->env) == -1)
		{
			error_print(myvars, NULL);
			_exit(1);
		}
	}
	else
	{
		wait(&myvars->status);
		if (WIFEXITED(myvars->status))
		{

			myvars->status = WEXITSTATUS(myvars->status);
		}
		else if (WIFSIGNALED(myvars->status) && WTERMSIG(myvars->status) == SIGINT)
		{
			myvars->status = 130;
		}

		return (0);
	}
	myvars->status = 127;
	return (1);
}
