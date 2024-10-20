#include<stdio.h>  
#define N 5  
int stack1[N], stack2[N];     
int top1=-1, top2=-1;   
int count=0;  

void push1(int data)  
{  
    if(top1 == N-1)  
    {  
        printf("\nStack is overflow...");  
    }  
    else  
    {  
        top1++;     
        stack1[top1] = data;    
    }  
}  

int pop1()  
{  
    if(top1 == -1)  
    {  
        printf("\nStack is empty..");  
        return -1;
    }  
    else  
    {  
        int a = stack1[top1];   
        top1--;   
        return a;   
    }  
}   

void push2(int x)  
{  
    if(top2 == N-1)  
    {  
        printf("\nStack is full..");  
    }  
    else  
    {  
        top2++;   
        stack2[top2] = x;   
    }  
}   

int pop2()  
{  
    if(top2 == -1)
    {
        printf("\nStack2 is empty..");
        return -1;
    }
    else
    {
        int element = stack2[top2];  
        top2--;    
        return element;  
    }
}   

void enqueue(int x)  
{  
    push1(x);  
    count++;  
}  

void dequeue()  
{  
    if((top1 == -1) && (top2 == -1))  
    {  
        printf("\nQueue is empty\n");  
    }  
    else  
    {  
        for(int i=0; i<count; i++)  
        {  
            int element = pop1();  
            push2(element);  
        }  
        int b = pop2();  
        printf("\nThe dequeued element is %d\n", b);  
        count--;  
        for(int i=0; i<count; i++)  
        {  
            int a = pop2();  
            push1(a);   
        }  
    }  
}   

void display()  
{  
    if(top1 == -1)  
    {  
        printf("\nQueue is empty\n");  
    }  
    else  
    {  
        printf("\nQueue elements: ");  
        for(int i = 0; i <= top1; i++)  
        {  
            printf("%d, ", stack1[i]);  
        }  
        printf("\n");
    }  
}  

void main()  
{  
    int choice, value;
    
    while(1)  
    {  
        printf("\n\nQueue using Stacks");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)  
        {  
            case 1:  
                if(top1 == N-1) 
                {
                    printf("\nQueue is full!");
                }
                else 
                {
                    printf("\nEnter the value to enqueue: ");  
                    scanf("%d", &value);
                    enqueue(value);  
                }
                break;  
            case 2:  
                dequeue();  
                break;  
            case 3:  
                display();  
                break;  
            case 4:  
                printf("\nExiting");
                return;
            default:  
                printf("\nInvalid choice, please try again.");
        }  
    }  
}  
