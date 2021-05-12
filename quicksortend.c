#include "quicksort.h"

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


int Partition(int *arr, int front, int end)
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

int Partition2(char **arr, int front, int end)
{
    int i = front -1;
    for (int j=front; j<end; j++)
    {
        if(strcmp (arr[j] , arr[end])<0)
        {
            i++;
            swap2(arr+i, arr+j);
        }
    }
    i++;
    swap2(arr+i, arr+end);
    return i;
}


void QuickSort1(int *arr, int front, int end)
{
    if (front < end)
    {
        int pivot = Partition(arr, front, end);
        QuickSort1(arr, front, pivot - 1);
        QuickSort1(arr, pivot + 1, end);
    }
}
void QuickSort2(char **arr, int front, int end)
{
    if (front < end)
    {
        int pivot = Partition2(arr, front, end);
        QuickSort2(arr, front, pivot - 1);
        QuickSort2(arr, pivot + 1, end);
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
    QuickSort1(numstr, 0, 1000000-1);
    gettimeofday(&tv2, NULL);
    //for (int i=0; i < 1000000; i++)
        //printf("%d\n", numstr[i]);
    //printf("\n");
    double diff = (tv2.tv_sec - tv1.tv_sec) + (tv2.tv_usec - tv1.tv_usec) / 1000000.0;
    printf("%fs\n", diff);
    fclose(file1);

    gettimeofday(&tv3, NULL);
    QuickSort2(arrstr, 0, 1000000-1);
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
