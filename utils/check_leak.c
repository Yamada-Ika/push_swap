#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

__attribute__((destructor)) void	destructor(void)
{
	char	cmd[50];

	sprintf(cmd, "leaks %d", getpid());
	system(cmd);
}
