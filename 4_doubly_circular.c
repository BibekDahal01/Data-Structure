#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly circular linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// Function to insert a node at the beginning of the 
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Node with data %d inserted at the beginning.\n", data);
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
    printf("Node with data %d inserted at the end.\n", data);
}

// Function to insert a node at a given position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position must be >= 1.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int count = 1;

    do {
        if (count == position - 1) {
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            printf("Node with data %d inserted at position %d.\n", data, position);
            return;
        }
        current = current->next;
        count++;
    } while (current != *head);

    printf("Position %d is out of bounds.\n", position);
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* toDelete = *head;

    if (toDelete->next == toDelete) { // Only one node in the list
        *head = NULL;
    } else {
        toDelete->next->prev = toDelete->prev;
        toDelete->prev->next = toDelete->next;
        *head = toDelete->next;
    }

    free(toDelete);
    printf("Node deleted from the beginning.\n");
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* toDelete = (*head)->prev;

    if (toDelete->next == toDelete) { // Only one node in the list
        *head = NULL;
    } else {
        toDelete->prev->next = *head;
        (*head)->prev = toDelete->prev;
    }

    free(toDelete);
    printf("Node deleted from the end.\n");
}

// Function to delete a node at a given position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position. Position must be >= 1.\n");
        return;
    }

    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    struct Node* current = *head;
    int count = 1;

    do {
        if (count == position) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            printf("Node deleted from position %d.\n", position);
            return;
        }
        current = current->next;
        count++;
    } while (current != *head);

    printf("Position %d is out of bounds.\n", position);
}

// Function to display the list in forward direction
void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("List (Forward): ");
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}

// Function to display the list in backward direction
void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head->prev;
    printf("List (Backward): ");
    do {
        printf("%d <-> ", current->data);
        current = current->prev;
    } while (current != head->prev);
    printf("(head)\n");
}

// Function to free the entire list
void freeList(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    struct Node* current = *head;
    struct Node* nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != *head);

    *head = NULL;
    printf("List freed successfully.\n");
}

// Function to display the menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Insert at the beginning\n");
    printf("2. Insert at the end\n");
    printf("3. Insert at a given position\n");
    printf("4. Delete from the beginning\n");
    printf("5. Delete from the end\n");
    printf("6. Delete at a given position\n");
    printf("7. Display the list (Forward)\n");
    printf("8. Display the list (Backward)\n");
    printf("9. Free the list\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 7:
                displayForward(head);
                break;
            case 8:
                displayBackward(head);
                break;
            case 9:
                freeList(&head);
                break;
            case 10:
                freeList(&head);
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}