#include<stdio.h>
# define max 3
int dq[max];
int front=-1;
int rear=-1;
void insert_right(int element) {
    if ((front == 0 && rear == max - 1) || (front == rear + 1)) {
        printf("Overflow \n");
        return; 
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == max - 1) {
        rear = 0;
    } else {
        rear = rear + 1;
    }
    dq[rear] = element;
}

void insert_left(int element) {
    if ((front == 0 && rear == max - 1) || (front == rear + 1)) {
        printf("Overflow \n");
        return; 
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = max - 1;
    } else {
        front = front - 1;
    }
    dq[front] = element;
}

void delete_left()
{
    if(front==-1)
    {
        printf("Underflow \n");
        return;
    }
    printf("The Deleted Queue is %d \n",dq[rear]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==max-1)
    {
        front=0;
    }
    else{
        front=front+1;
    }
}
void delete_right()
{
    if(front==-1)
    {
        printf("Underflow \n");
        return;
    }
    printf("The Deleted Queue is %d \n",dq[front]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(rear==0)
    {
        rear=max-1;
    }
    else{
        rear=rear-1;
    }
}
void display() {
    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    int i = front;
    if(front <= rear) {
        while(i <= rear) {
            printf("%d ", dq[i]);
            i++;
        }
    } else {
        while(i <= max-1) {
            printf("%d ", dq[i]);
            i++;
        }
        i = 0;
        while(i <= rear) {
            printf("%d ", dq[i]);
            i++;
        }
    }
    printf("\n");
}
int main()
{
 int choice, element;
    while(1) {
        printf("\nDouble-ended Queue Operations: \n");
        printf("1. Insert at right\n");
        printf("2. Insert at left\n");
        printf("3. Delete from left\n");
        printf("4. Delete from right\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter element to insert at right: ");
                scanf("%d", &element);
                insert_right(element);
                break;
            case 2:
                printf("Enter element to insert at left: ");
                scanf("%d", &element);
                insert_left(element);
                break;
            case 3:
                delete_left();
                break;
            case 4:
                delete_right();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;   
}