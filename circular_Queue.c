// #include <stdio.h>
// #include <stdlib.h>

// typedef struct queue {
//     int size;
//     int capacity;
//     int front;
//     int rear;
//     int *arr;
// } queue;

// queue *createQueue(int size) {
//     queue *q = (queue *)malloc(sizeof(queue));
//     q->size = size;
//     q->capacity = 0;
//     q->front = -1;
//     q->rear = -1;
//     q->arr = (int *)malloc(size * sizeof(int));
//     return q;
// }

// int isFull(queue *q) {
//     return (q->capacity == q->size);
// }

// int isEmpty(queue *q) {
//     return (q->capacity == 0);
// }

// void enQueue(queue *q, int val) {
//     if (isFull(q)) {
//         printf("Queue is full\n");
//         return;
//     }
//     if (isEmpty(q)) {
//         q->front = 0;
//         q->rear = 0;
//     } else {
//         q->rear = (q->rear + 1) % q->size;
//     }
//     q->arr[q->rear] = val;
//     q->capacity++;
// }

// int deQueue(queue *q) {
//     if (isEmpty(q)) {
//         printf("Queue is empty\n");
//         return -99999;
//     }
//     int val = q->arr[q->front];
//     if (q->front == q->rear) {
//         q->front = -1;
//         q->rear = -1;
//     } else {
//         q->front = (q->front + 1) % q->size;
//     }
//     q->capacity--;
//     return val;
// }

// int peekFront(queue *q) {
//     if (isEmpty(q)) {
//         printf("Queue is empty\n");
//         return -99999;
//     }
//     return q->arr[q->front];
// }

// int peekRear(queue *q) {
//     if (isEmpty(q)) {
//         printf("Queue is empty\n");
//         return -99999;
//     }
//     return q->arr[q->rear];
// }

// void display(queue *q) {
//     if (isEmpty(q)) {
//         printf("Queue is empty\n");
//         return;
//     }
//     int i = q->front;
//     do {
//         printf("%d ", q->arr[i]);
//         i = (i + 1) % q->size;
//     } while (i != (q->rear + 1) % q->size);
//     printf("\n");
// }

// void destroyQueue(queue *q) {
//     free(q->arr);
//     free(q);
// }

// int main() {
//     queue *q = NULL;
//     int size, choice, val;
//     printf("Enter the size of the queue: ");
//     scanf("%d", &size);
//     q = createQueue(size);

//     do {
//         printf("\n1. Enqueue\n");
//         printf("2. Dequeue\n");
//         printf("3. Peek Front\n");
//         printf("4. Peek Rear\n");
//         printf("5. Display\n");
//         printf("6. isEmpty\n");
//         printf("7. isFull\n");
//         printf("8. Exit\n");
//         printf("Enter your choice : ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter the value to enqueue: ");
//                 scanf("%d", &val);
//                 enQueue(q, val);
//                 display(q);
//                 break;
//             case 2:
//                 val = deQueue(q);
//                 if (val != -99999) {
//                     printf("Dequeued value: %d\n", val);
//                 }
//                 display(q);
//                 break;
//             case 3:
//                 val = peekFront(q);
//                 if (val != -99999) {
//                     printf("Front value: %d\n", val);
//                 }
//                 break;
//             case 4:
//                 val = peekRear(q);
//                 if (val != -99999) {
//                     printf("Rear value: %d\n", val);
//                 }
//                 break;
//             case 5:
//                 display(q);
//                 break;
//             case 6:
//                 if (isEmpty(q)) {
//                     printf("Queue is empty\n");
//                 } else {
//                     printf("Queue is not empty\n");
//                 }
//                 break;
//             case 7:
//                 if (isFull(q)) {
//                     printf("Queue is full\n");
//                 } else {
//                     printf("Queue is not full\n");
//                 }
//                 break;
//             case 8:
//                 printf("Exiting...\n");
//                 destroyQueue(q);
//                 break;
//             default:
//                 printf("Invalid choice\n");
//         }
//     } while (choice != 8);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

// Structure to represent a circular queue
struct CircularQueue {
    int front, rear;
    int arr[MAX];
};

// Function to initialize the queue
void initQueue(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct CircularQueue* q) {
    if ((q->rear + 1) % MAX == q->front) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

// Function to add an element to the queue (enqueue)
void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full, cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {  // If the queue is empty
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    } else {
        int dequeuedValue = q->arr[q->front];
        if (q->front == q->rear) {  // If there's only one element
            q->front = q->rear = -1;  // Reset queue
        } else {
            q->front = (q->front + 1) % MAX;
        }
        return dequeuedValue;
    }
}

// Function to display the elements of the queue
void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->arr[i]);
            i = (i + 1) % MAX;
        }
        printf("%d ", q->arr[q->rear]);  // Display the last element
        printf("\n");
    }
}

// Driver code
int main() {
    struct CircularQueue q;
    initQueue(&q);  // Initialize the queue

    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}
