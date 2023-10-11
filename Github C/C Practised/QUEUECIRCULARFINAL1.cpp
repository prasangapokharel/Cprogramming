#include <stdio.h>
#include <conio.h>
#define MAX 5

struct queue {
    int item[MAX];
    int front;
    int rear;
};

void insert(struct queue *q, int val) {
    if ((q->rear + 1) % MAX == q->front) {
        printf("\nQueue is full. You cannot insert more.\n");
    } else if (q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
        q->item[q->rear] = val;
        printf("\nItem inserted successfully.\n");
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->item[q->rear] = val;
        printf("\nItem inserted successfully.\n");
    }
}

int remove(struct queue *q) {
    int val;
    if (q->front == -1 && q->rear == -1) {
        printf("\nQueue is empty. You cannot remove any items.\n");
        return 0;
    } else if (q->front == q->rear) {
        val = q->item[q->front];
        q->front = q->rear = -1;
    } else {
        val = q->item[q->front];
        q->front = (q->front + 1) % MAX;
    }

    printf("\nItem removed successfully.\n");
    return val;
}


void display(struct queue *q) {
    int i;
    printf("\nQueue contains:\n");

    if (q->front == -1 && q->rear == -1) {
        printf("Empty\n");
        return;
    }

    if (q->front <= q->rear) {
        for (i = q->front; i <= q->rear; i++) {
            printf("%d\t", q->item[i]);
        }
    } else {
        for (i = q->front; i < MAX; i++) {
            printf("%d\t", q->item[i]);
        }
        for (i = 0; i <= q->rear; i++) {
            printf("%d\t", q->item[i]);
        }
    }

    printf("\n");
}


int main() {
    char ch;
    int val;
    struct queue q;
    q.front = -1;
    q.rear = -1; // Empty queue initialization
    
    printf("WELCOME TO MENU\n");
    
    while (1) {
        printf("1. Display\n");
        printf("2. Insert\n");
        printf("3. Remove\n");
        printf("Enter your choice or press 'N' or 'No' to exit: ");
        scanf(" %c", &ch);
        
        switch (ch) {
            case '1':
                display(&q);
                break;
            case '2':
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                insert(&q, val);
                break;
            case '3':
                val = remove(&q);
                if (val != 0) {
                    printf("Removed item: %d\n", val);
                }
                break;
            case 'N':
            case 'n':
                printf("Exiting program.\n");
                getch();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        // Clear the input buffer
        while (getchar() != '\n')
            continue;
        
        printf("\n");
    }
}

