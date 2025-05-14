#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int size;
    int capacity;
    int front;
    int rear;
    int *arr;
} queue;

queue *createQueue(int size) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->size = size;
    q->capacity = 0;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(size * sizeof(int));
    return q;
}

int isFull(queue *q) {
    return (q->capacity == q->size);
}

int isEmpty(queue *q) {
    return (q->capacity == 0);
}

void enQueue(queue *q, int val) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }
    q->arr[q->rear] = val;
    q->capacity++;
}

int deQueue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -99999;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    q->capacity--;
    return val;
}

int peekFront(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -99999;
    }
    return q->arr[q->front];
}

int peekRear(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -99999;
    }
    return q->arr[q->rear];
}

void display(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    do {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    } while (i != (q->rear + 1) % q->size);
    printf("\n");
}

void destroyQueue(queue *q) {
    free(q->arr);
    free(q);
}

int main() {
    queue *q = NULL;
    int size, choice, val;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    q = createQueue(size);

    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek Front\n");
        printf("4. Peek Rear\n");
        printf("5. Display\n");
        printf("6. isEmpty\n");
        printf("7. isFull\n");
        printf("8. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &val);
                enQueue(q, val);
                display(q);
                break;
            case 2:
                val = deQueue(q);
                if (val != -99999) {
                    printf("Dequeued value: %d\n", val);
                }
                display(q);
                break;
            case 3:
                val = peekFront(q);
                if (val != -99999) {
                    printf("Front value: %d\n", val);
                }
                break;
            case 4:
                val = peekRear(q);
                if (val != -99999) {
                    printf("Rear value: %d\n", val);
                }
                break;
            case 5:
                display(q);
                break;
            case 6:
                if (isEmpty(q)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 7:
                if (isFull(q)) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            case 8:
                printf("Exiting...\n");
                destroyQueue(q);
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 8);

    return 0;
}