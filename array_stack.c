#include <stdio.h>
#define MAX 6 

int stack[MAX], top = -1; // Stack is empty

int isFull() {
    return (top == MAX - 1);
}

int isEmpty() {
    return (top == -1);
}

void push(int value) {
    if (!isFull()) {
        stack[++top] = value;
        printf("%d pushed to stack.\n", value);
    } else {
        printf("Stack Overflow! Cannot push %d.\n", value);
    }
}

int pop() {
    if (!isEmpty()) {
        printf("%d popped from stack.\n", stack[top]);
        return stack[top--];
    } else {
        printf("Stack Underflow! No elements to pop.\n");
        return -1;
    }
}

int peek() {
    if (!isEmpty()) {
        return stack[top];
    } else {
        printf("Stack is empty.\n");
        return -1;
    }
}

void display() {
    if (!isEmpty()) {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    } else {
        printf("Stack is empty.\n");
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Top element: %d\n", peek());
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
