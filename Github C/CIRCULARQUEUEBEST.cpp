#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

struct queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initialize(struct queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isFull(struct queue* q) {
    return ((q->front == 0 && q->rear == MAX_SIZE - 1) || (q->rear == (q->front - 1) % (MAX_SIZE - 1)));
}

bool isEmpty(struct queue* q) {
    return (q->front == -1);
}

void enqueue(struct queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue value %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}

void display(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contains: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", q->items[q->rear]);
}

int main() {
    struct queue q;
    initialize(&q);

    int choice, item;
    while (1) {
        printf("\nSELECT OPTION\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;
            case 2:
                item = dequeue(&q);
                if (item != -1) {
                    printf("Dequeued %d\n", item);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

