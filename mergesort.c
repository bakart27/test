#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char arr[], int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid + 1) + 1;
    char *A=malloc(lenA);
    char *B=malloc(lenB);
    for(int i = 0; i < lenA; i++)
        A[i] = arr[head + i];
    for(int i = 0; i < lenB; i++)
        B[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = head;
    while(i < lenA && j < lenB)
    {
        if(A[i] < B[j])
        {
            arr[k] = A[i];
            i++;
        }
        else
        {
            arr[k] = B[j];
            j++;
        }
        k++;
    }
    while(i < lenA)
    {
        arr[k] = A[i];
        i++;
        k++;
    }
    while(j < lenB)
    {
        arr[k] = B[j];
        j++;
        k++;
    }
}
void merge_sort(char arr[], int head, int tail)
{
    if(head < tail)
    {
        int mid = (head + tail) / 2;
        merge_sort(arr, head, mid);
        merge_sort(arr, mid+1, tail);
        merge(arr, head, mid, tail);
    }
}

int main()
{
    int a=0;
    char *arr = malloc(1000000);
    for(int i = 0; i < 1000000; i++)
    {
        a = rand() % 36;
        if(a >= 0 && a <= 9)
            arr[i] = a + 48;
        else
            arr[i] = a+87;
    }
    merge_sort(arr, 0, 1000000-1);
    for(int i = 0; i < 1000000; i++)
        printf("%c ", arr[i]);
    return 0;
}
