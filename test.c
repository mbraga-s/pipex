#include "libft.h"
#include "ft_printf.h"

int main(void)
{
    char cmd[] = "/usr/bin/ls";
    char *argVec[] = {"mamamia", "-a", "-1", NULL};
    char *envVec[] = {NULL};

    printf("Start of execve call %s:\n", cmd);
    printf("===================\n");
    if (execve(cmd, argVec, envVec) == -1)
    {
        perror("Could not execute execve:");
    }
    printf("Oops something went wrong!\n");
    return (0);
}
