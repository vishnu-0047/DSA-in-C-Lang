#include <stdio.h>
#define MAX 10

int queue[MAX], front = -1, rear = -1;

void enqueue(int val) {
    if ((rear + 1) % MAX == front) return;
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = val;
}

int dequeue() {
    if (front == -1) return -1;
    int val = queue[front];
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
    return val;
}

int main() {
    int n, tq, bt[MAX], rem_bt[MAX], tat[MAX], wt[MAX], time = 0, i;

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    printf("Enter burst times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
        enqueue(i);
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    while (front != -1) {
        int process = dequeue();
        if (rem_bt[process] > tq) {
            time += tq;
            rem_bt[process] -= tq;
            enqueue(process);
        } else {
            time += rem_bt[process];
            tat[process] = time;
            wt[process] = tat[process] - bt[process];
        }
    }

    printf("\nProcess\tBurst time\tTurnaround time\tWaiting time\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], tat[i], wt[i]);

    return 0;
}
