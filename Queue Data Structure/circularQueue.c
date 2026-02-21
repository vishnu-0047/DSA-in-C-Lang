#include <stdio.h>
#define max 5
int queue[max], front = -1, rear = -1;

void enqueue(int val) {
    if ((rear + 1) % max == front) {
        printf("Queue overflow.");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % max;
    }
    queue[rear] = val;
}

void dequeue() {
    if (front == -1) {
        printf("Queue underflow.");
    } else {
        printf("Deleted element is %d.", queue[front]);
        if (front == rear) {
            front = rear = -1;  // Reset when last element is dequeued
        } else {
            front = (front + 1) % max;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue underflow.");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % max;
    }
}

void peek() {
    if (front == -1) {
        printf("Queue underflow.");
        return;
    }
    printf("Element at front is %d.", queue[front]);
}

int main() {
    int choice, val;
    printf("1. Enqueue 2. Dequeue 3. Display 4. Peek 5. Exit");
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to add to queue: ");
            scanf("%d", &val);
            enqueue(val);
            break;
            case 2:
                dequeue();
            break;
            case 3:
                display();
            break;
            case 4:
                peek();
            break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!");
        }
    }
}
