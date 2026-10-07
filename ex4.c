#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    char line[256], *args[32];

    while (1) {
        waitpid(-1, NULL, WNOHANG);
        printf("shell> ");
        fflush(stdout);

        if (!fgets(line, sizeof(line), stdin))
            break;

        int i = 0;
        char *word = strtok(line, " \n");
        while (word && i < 31) {
            args[i++] = word;
            word = strtok(NULL, " \n");
        }
        args[i] = NULL;

        if (!args[0])
            continue;
        if (!strcmp(args[0], "exit"))
            break;

        if (fork() == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        }
    }

    return 0;
}
