#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL; // Initialize to NULL (not part of any list yet)
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtFirst(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Circular link (points to itself)
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
    printf("Node with data %d inserted at the beginning.\n", data);
}

void insertAtLast(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; 
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    printf("Node with data %d inserted at the end.\n", data);
}

void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position! Position should be >= 1.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        if (position == 1) {
            *head = newNode;
            newNode->next = *head; // Circular link (points to itself)
            printf("Node with data %d inserted at position %d.\n", data, position);
        } else {
            printf("Invalid position! List is empty.\n");
        }
        return;
    }
    if (position == 1) {
        insertAtFirst(head, data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
        if (temp == *head) {
            printf("Invalid position! Position exceeds the list size.\n");
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node with data %d inserted at position %d.\n", data, position);
}

void deleteAtFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;
    if (temp->next == *head) { 
        *head = NULL;
    } else {
        struct Node* lastNode = *head;
        while (lastNode->next != *head) {
            lastNode = lastNode->next;
        }
        *head = temp->next;
        lastNode->next = *head;
    }
    free(temp);
    printf("Node deleted from the beginning.\n");
}

void deleteAtLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp->next == *head) { 
        *head = NULL;
        free(temp);
        printf("Node deleted from the end.\n");
        return;
    }
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = *head;
    free(temp);
    printf("Node deleted from the end.\n");
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    if (position < 1) {
        printf("Invalid position! Position should be >= 1.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (position == 1) {
        deleteAtFirst(head);
        return;
    }
    for (int i = 1; i < position; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == *head) {
            printf("Invalid position! Position exceeds the list size.\n");
            return;
        }
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d.\n", position);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\n--- Circular Linked List Operations ---\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete at First\n");
        printf("5. Delete at Last\n");
        printf("6. Delete at Specific Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at first: ");
                scanf("%d", &data);
                insertAtFirst(&head, data);
                break;
            case 2:
                printf("Enter data to insert at last: ");
                scanf("%d", &data);
                insertAtLast(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteAtFirst(&head);
                break;
            case 5:
                deleteAtLast(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}