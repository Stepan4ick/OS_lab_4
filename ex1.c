#include <stdio.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
    pid_t p1 = fork();
    clock_t start = clock();

    if (p1 == 0) {
        printf("Child 1: PID=%d PPID=%d time=%.3f ms\n", getpid(), getppid(),
               (double)(clock() - start) * 1000 / CLOCKS_PER_SEC);
        return 0;
    }

    pid_t p2 = fork();
    clock_t start2 = clock();

    if (p2 == 0) {
        printf("Child 2: PID=%d PPID=%d time=%.3f ms\n", getpid(), getppid(),
               (double)(clock() - start2) * 1000 / CLOCKS_PER_SEC);
        return 0;
    }

    wait(NULL);
    wait(NULL);
    printf("Main: PID=%d PPID=%d time=%.3f ms\n", getpid(), getppid(),
           (double)(clock() - start) * 1000 / CLOCKS_PER_SEC);
    return 0;
}
