// #include<stdio.h>
// #include<stdlib.h>

// typedef struct queue{
//     int * arr;
//     int capacity;
//     int front;
//     int rear;
// }queue;

// queue * createQueue(int capacity){
//     queue * q = (queue *)malloc(sizeof(queue));
//     q->capacity = capacity;
//     q->front = q->rear = -1;
//     q->arr = (int *)malloc(sizeof(int) * capacity);
//     return q;
// }

// int isFull(queue * q){
//     if(q->rear == q->capacity-1){
//         return 1;
//     } else {
//         return 0;
//     }
// }

// void enqueue(queue * q, int val){
//     if(isFull(q)){
//         printf("Queue is full\n");
//         return;
//     } else {
//         if(q->rear == -1){
//             q->front = 0;
//             q->rear = 0;
//             q->arr[q->rear] = val;            
//         } else {
//             q->arr[++q->rear] = val;
//         }
//     }
// }

// int isEmpty(queue * q){
//     if(q->front == -1){
//         return 1;
//     } else {
//         return 0;
//     }
// }

// int dequeue(queue * q){
//     if(isEmpty(q)){
//         printf("Queue is empty\n");
//         return -99999;
//     } else {
//         int val = q->arr[q->front];
//         if(q->front == q->rear){
//             q->front = q->rear = -1;
//         } else {
//             q->front++;
//         }
//         return val;
//     }
// }

// int getFront(queue * q){
//     if(isEmpty(q)){
//         printf("Queue is empty\n");
//         return -99999;
//     } else {
//         return q->arr[q->front];
//     }
// }

// int getRear(queue * q){
//     if(isEmpty(q)){
//         printf("Queue is empty\n");
//         return -99999;
//     } else {
//         return q->arr[q->rear];
//     }
// }

// void display(queue * q){
//     if(isEmpty(q)){
//         printf("Queue is empty\n");
//         return;
//     } else {
//         for(int i = q->front; i <= q->rear; i++){
//             printf("%d ", q->arr[i]);
//         }
//         printf("\n");
//     }
// }

// int main(){
//     queue * q = NULL;
//     int capacity ;
//     int choice;
//     int val;
//     printf("Enter the capacity of the queue: ");
//     scanf("%d", &capacity);
//     q = createQueue(capacity);
//     do{
//         printf("1. Enquque\n");
//         printf("2. Dequeue\n");
//         printf("3. Get Front\n");
//         printf("4. Get Rear\n");
//         printf("5. isEmpty\n");
//         printf("6. isFull\n");
//         printf("7. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);
//         switch(choice){
//             case 1:
//                 printf("Enter the value to be enqueued: ");
//                 scanf("%d", &val);
//                 enqueue(q, val);
//                 display(q);
//                 break;
//             case 2:
//                 val = dequeue(q);
//                 if(val != -99999){
//                     printf("Dequeued value: %d\n", val);
//                 }
//                 display(q);
//                 break;
//             case 3:
//                 val = getFront(q);
//                 if(val != -99999){
//                     printf("Front value: %d\n", val);
//                 }
//                 break;
//             case 4:
//                 val = getRear(q);
//                 if(val != -99999){
//                     printf("Rear value: %d\n", val);
//                 }
//                 break;
//             case 5:
//                 if(isEmpty(q)){
//                     printf("Queue is empty\n");
//                 } else {
//                     printf("Queue is not empty\n");
//                 }
//                 break;
//             case 6:
//                 if(isFull(q)){
//                     printf("Queue is full\n");
//                 } else {
//                     printf("Queue is not full\n");
//                 }
//                 break;
//             case 7:
//                 break;
//         }
//     }while(choice >= 1 && choice <= 6);
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

// Structure to represent a queue
struct Queue {
    int front, rear;
    int arr[MAX];
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    if (q->rear == MAX - 1) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        return 1;
    }
    return 0;
}

// Function to add an element to the queue (enqueue)
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full, cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;  // If the queue is empty
        }
        q->rear++;
        q->arr[q->rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    } else {
        int dequeuedValue = q->arr[q->front];
        q->front++;
        return dequeuedValue;
    }
}

// Function to display the elements of the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

// Driver code
int main() {
    struct Queue q;
    initQueue(&q);  // Initialize the queue

    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
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
