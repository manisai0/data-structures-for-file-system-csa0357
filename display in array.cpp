#include <stdio.h>

void displayArray();

int main()
{
    int size;
    printf("Hello. What will be the size of the new array?\n");
    scanf("%d", &size);

    int myarray[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d. element\n" , (i + 1));
        scanf("%d", &myarray[i]);
    }

    return 0;
}

void displayArray(int myarray[], int size)
{
    printf("Your array is: ");
    for (int i = 0; i < size; i++)
    {
         printf("%d ", myarray[i]);
    }
    return;
}
