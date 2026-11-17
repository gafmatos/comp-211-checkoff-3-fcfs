#include <stdio.h>

typedef struct
{
    int id;
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
        printf("P%d waits %2d ms\n", p[i].id, p[i].wait);
    }
    double avg = (double)total / len;

    printf("Average wait: %.2f\n", avg);
    printf("\n");
}

int main()
{
    Process slower[] = {{1, 24, 0}, {2, 3, 24}, {3, 3, 27}};
    Process faster[] = {{2, 3, 0}, {3, 3, 0}, {1, 24, 0}};
    iterateProcess(slower, 3);
    iterateProcess(faster, 3);

    return 0;
}