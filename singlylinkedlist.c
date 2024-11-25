#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void linkedListTraversal(struct Node* ptr) {
    if (ptr == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (!ptr) {
        printf("Memory allocation failed\n");
        return head;
    }
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node* insertAtIndex(struct Node* head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (!ptr) {
        printf("Memory allocation failed\n");
        return head;
    }
    struct Node* p = head;
    int i = 0;

    while (i != index - 1 && p != NULL) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("Invalid index\n");
        free(ptr);
        return head;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (!ptr) {
        printf("Memory allocation failed\n");
        return head;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL) {
        return ptr;
    }
    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    return head;
}

struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("The list is already empty.\n");
        return NULL;
    }
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node* deleteAtIndex(struct Node* head, int index) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }
    if (index == 0) {
        return deleteFirst(head);
    }
    struct Node* p = head;
    struct Node* q = head->next;
    for (int i = 0; i < index - 1; i++) {
        if (q == NULL) {
            printf("Invalid index\n");
            return head;
        }
        p = p->next;
        q = q->next;
    }
    if (q == NULL) {
        printf("Invalid index\n");
        return head;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node* deleteAtLast(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* p = head;
    struct Node* q = head->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

void searchInList(struct Node* head, int value) {
    int index = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            printf("Value %d found at index %d.\n", value, index);
            return;
        }
        current = current->next;
        index++;
    }
    printf("Value %d not found in the list.\n", value);
}

int main() {
    int choice, data, index, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Traverse the list\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at an index\n");
        printf("4. Insert at the end\n");
        printf("5. Delete the first node\n");
        printf("6. Delete at an index\n");
        printf("7. Delete the last node\n");
        printf("8. Search for a value\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                linkedListTraversal(head);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                head = insertAtFirst(head, data);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the index: ");
                scanf("%d", &index);
                head = insertAtIndex(head, data, index);
                break;
            case 4:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 5:
                head = deleteFirst(head);
                break;
            case 6:
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                head = deleteAtIndex(head, index);
                break;
            case 7:
                head = deleteAtLast(head);
                break;
            case 8:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                searchInList(head, value);
                break;
            case 9:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
