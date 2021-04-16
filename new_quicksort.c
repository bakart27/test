#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(char *arr, int front, int end)
{
    int i = front -1;
    for (int j=front; j<end; j++)
    {
        if (arr[j] < arr[end])
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}

void QuickSort(char *arr, int front, int end)
{
    if (front < end)
    {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}

int main()
{
    int a=0;
    char *arr=malloc(1000000);
    for(int i=0; i<1000000; i++)
    {
        a = rand() % 36;
        if(a>=0 && a <=9)
        	arr[i] = a+48;
        else
            arr[i] = a+87;
    }
    QuickSort(arr, 0, 1000000-1);
    for (int i=0; i < 1000000; i++)
        printf("%c ", arr[i]);
    printf("\n");
    return 0;
}
