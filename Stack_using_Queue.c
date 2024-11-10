#include <stdio.h>
#define MAX 3

int q1[MAX], q2[MAX];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

int isEmpty(int front, int rear) {
    return (front == -1);
}

void enqueue(int q[], int *front, int *rear, int value) {
    if (*rear == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    if (*front == -1) {
        *front = 0;
    }
    (*rear)++;
    q[*rear] = value;
}

int dequeue(int q[], int *front, int *rear) {
    if (isEmpty(*front, *rear)) {
        printf("Stack Underflow\n");
        return -1;
    }
    int value = q[*front];
    if (*front == *rear) {
        *front = *rear = -1;
    } else {
        (*front)++;
    }
    return value;
}

void push(int x) {
    enqueue(q1, &front1, &rear1, x);
}

void pop() {
    if (isEmpty(front1, rear1)) {
        printf("Stack Underflow\n");
        return;
    }
    while (front1 != rear1) {
        enqueue(q2, &front2, &rear2, dequeue(q1, &front1, &rear1));
    }
    int poppedElement = dequeue(q1, &front1, &rear1);
    printf("Popped element: %d\n", poppedElement);
    
    for (int i = 0; i <= rear2; i++) {
        q1[i] = q2[i];
    }
    front1 = front2;
    rear1 = rear2;
    front2 = rear2 = -1;
}

void display() {
    if (isEmpty(front1, rear1)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = front1; i <= rear1; i++) {
        printf("%d ", q1[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
            display();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
