#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    int n = atoi(argv[1]);
    if (n < 0 || n > 5)
        return 1;

    for (int i = 0; i < n; i++) {
        fork();
        sleep(5);
    }

    return 0;
}
