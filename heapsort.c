#include "common.h"
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap2(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify1(int *arr, int n, int i)
{
    int largest = i;
    int l = i*2 +1;
    int r = i*2 +2;
    if (l < n && arr[l] > arr[largest])
        largest=l;
    if (r<n && arr[r] > arr[largest])
        largest=r;
    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify1(arr, n, largest);
    }
}
void heapify2(char **arr, int n, int i)
{
    int largest = i;
    int l = i*2 +1;
    int r = i*2 +2;
    if (l < n && strcmp(arr[l], arr[largest])>0)
        largest=l;
    if (r<n && strcmp(arr[r], arr[largest])>0)
        largest=r;
    if(largest != i)
    {
        swap2(arr+i, arr+largest);
        heapify2(arr, n, largest);
    }
}
void heapSort1(int *arr, int n)
{
    for (int i= n/2-1;i>=0; i--)
    heapify1(arr, n, i);
    for (int i=n-1; i>0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify1(arr, i, 0);
    }
}
void heapSort2(char **arr, int n)
{
    for (int i= n/2-1;i>=0; i--)
    heapify2(arr, n, i);
    for (int i=n-1; i>0; i--)
    {
        swap2(arr, arr+i);
        heapify2(arr, i, 0);
    }
}

int main()
{
    struct timeval tv1;
    struct timeval tv2;
    struct timeval tv3;
    struct timeval tv4;
    FILE *file1;
    file1 = fopen( "dataset1.txt","w" );
    FILE *file2;
    file2 = fopen( "dataset2.txt","w" );
    int *a = malloc(8000000);
    int ans=0;
    char ch;
    int *numstr = malloc(8000000);
    char **arr = NULL;
    arr = malloc(1000000*sizeof(char*));
    for(int i=0;i<1000000;i++)
        *(arr+i) = malloc(100*sizeof(char));
    char **arrstr = NULL;
    arrstr = malloc(1000000*sizeof(char*));
    for(int i=0;i<1000000;i++)
        *(arrstr+i) = malloc(100*sizeof(char));
    for(int i=0; i<1000000; i++)
    {
        a[i] = rand();
        for(int j=0; j<100; j++)
        {
            arr[i][j] = rand()%26 + 97;
        }
    }
    if( NULL == file1)
        return 1;
    else
    {
        for(int i=0; i<1000000; i++)
        {
            ans = a[i];
            fprintf(file1,"%d\n",ans);
        }
    }
    if( NULL == file2)
        return 1;
    else
    {
        for(int i=0;i<1000000;i++)
        {
            for(int j=0; j<100; j++)
            {
                ch=*(*(arr+i)+j);
                if(j!=99)
                    fprintf(file2,"%c",ch);
                else
                    fprintf(file2,"%c\n",ch);
            }
        }
    }
    fclose(file1);
    fclose(file2);
    file1=fopen("dataset1.txt","r");
    file2=fopen("dataset2.txt","r");
    int i=0;
    while(!feof(file1))
    {
        fscanf(file1,"%d",(numstr+i));
        i++;
    }
    i=0;
    while(!feof(file2))
    {
        fscanf(file2,"%s", *(arrstr+i));
        i++;
    }
    gettimeofday(&tv1, NULL);
    heapSort1(numstr,1000000);
    gettimeofday(&tv2, NULL);
    /*for (int i=0; i < 1000000; i++)
        printf("wow%d\n", numstr[i]);
    printf("\n");*/
    double diff = (tv2.tv_sec - tv1.tv_sec) + (tv2.tv_usec - tv1.tv_usec) / 1000000.0;
    printf("%fs\n", diff);
    fclose(file1);

    gettimeofday(&tv3, NULL);
    heapSort2(arrstr,1000000);
    gettimeofday(&tv4, NULL);
    for (int i=0; i < 1000000; i++)
    {
        for(int j=0; j<100;j++)
            printf("%c", arrstr[i][j]);
        printf("\n");
    }
    diff = (tv4.tv_sec - tv3.tv_sec) + (tv4.tv_usec - tv3.tv_usec) / 1000000.0;
    printf("%fs\n", diff);
    fclose(file2);

    return 0;
}
