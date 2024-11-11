#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void push() {
    int data;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Cannot push element (memory allocation failed)\n");
    } else {
        printf("Enter value: ");
        scanf("%d", &data);
        ptr->data = data;
        ptr->next = head;
        head = ptr;
        printf("Item Pushed\n");
    }
}

void pop() {
    struct node *ptr;
    if (head == NULL) {
        printf("Underflow (stack is empty)\n");
    } else {
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item Popped\n");
    }
}

void display() {
    struct node *ptr = head;
    if (ptr == NULL) {
        printf("Stack is Empty\n");
    } else {
        printf("Printing Stack elements:\n");
        while (ptr != NULL) {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
