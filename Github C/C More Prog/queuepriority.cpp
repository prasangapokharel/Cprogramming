#include <stdio.h>
#include <stdbool.h>

#define MAX 5

struct PriorityQueue {
  int items[MAX];
  int rear;  int size;
};

bool isFull(struct PriorityQueue* q) { return q->size == MAX; }

bool isEmpty(struct PriorityQueue* q) { return q->size == 0; }


void enqueue(struct PriorityQueue* q, int item) {
  if (isFull(q)) {
    printf("Priority queue is full!\n");
    return;
  }

  int i;
  for (i = q->size - 1; i >= 0; i--) {
    if (item < q->items[i])
      q->items[i + 1] = q->items[i];
    else
      break;
  }

  q->items[i + 1] = item;
  q->size++;

  printf("Enqueued element: %d\n", item);
}

int dequeue(struct PriorityQueue* q) {
  if (isEmpty(q)) {
    printf("Priority queue is empty!\n");
    return -1;
  }

  int item = q->items[0];

  for (int i = 1; i < q->size; i++) {
    q->items[i - 1] = q->items[i];
  }

  q->size--;

  return item;
}

void display(struct PriorityQueue* q) {
  if (isEmpty(q)) {
    printf("Priority queue is empty!\n");
    return;
  }

  printf("Priority queue:\n");

  for (int i = 0; i < q->size; i++) {
    printf("%d ", q->items[i]);
  }

  printf("\n");
}

int main() {
  struct PriorityQueue q;
  q.rear = -1;
  q.size = 0;

  int choice, item;

  while (1) {
    printf("Priority Queue Application\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the element to enqueue: ");
        scanf("%d", &item);
        enqueue(&q, item);
        break;

      case 2:
        item = dequeue(&q);
        if (item != -1)
          printf("Dequeued element: %d\n", item);
        break;

      case 3:
        display(&q);
        break;

      case 4:
        printf("Exiting the program.\n");
        return 0;

      default:
        printf("Invalid choice! Please enter a valid option.\n");
    }

    printf("\n");
  }

  return 0;
}

