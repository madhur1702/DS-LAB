#include<stdio.h>

int main()
{
    int a[5], i, j, temp;
    printf("Enter 5 elements:\n");
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);  // Corrected scanf
    }

    printf("\nArray Before Sorting: ");
    for(i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }

    // Sorting logic (Insertion Sort)
    for(i = 1; i < 5; i++)
    {
        temp = a[i];
        j = i - 1;

        // Shift elements to the right to make space for the current element
        while(j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;  // Place temp in the correct position
    }

    printf("\n\nArray After Sorting: ");
    for(i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
