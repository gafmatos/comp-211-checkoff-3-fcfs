#include <stdio.h>

typedef struct
{
    char name[3];
    int burst;
    int wait;
} Process;

void iterateProcess(Process p[], int len)
{
    int time = 0;
    int total = 0;
    for (int i = 0; i < len; i++)
    {
        p[i].wait = time;
        time += p[i].burst;
        total += p[i].wait;
        printf("%s waits %2d ms\n", p[i].name, p[i].wait);
    }
    double avg = (double)total / len;

    printf("Average wait: %.2f ms \n", avg);
    printf("\n");
}

int main()
{
    Process slower[] = {{"P1", 24, 0}, {"P2", 3, 24}, {"P3", 3, 27}};
    Process faster[] = {{"P2", 3, 0}, {"P3", 3, 0}, {"P1", 24, 0}};
    printf("\n");
    iterateProcess(slower, 3);
    iterateProcess(faster, 3);
    printf("\n");

    return 0;
}