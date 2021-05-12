#include "common.h"

void merge1(int *arr, int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid + 1) + 1;
    int *A=malloc(sizeof(int)*lenA);
    int *B=malloc(sizeof(int)*lenB);
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
void merge2(char **arr, int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid + 1) + 1;
    char **A=malloc(sizeof(char*)*lenA);
    for(int i=0;i<lenA;i++)
        *(A+i) = malloc(100*sizeof(char));
    char **B=malloc(sizeof(char*)*lenB);
    for(int i=0;i<lenB;i++)
        *(B+i) = malloc(100*sizeof(char));
    for(int i = 0; i < lenA; i++)
    {
        strcpy(A[i], arr[head+i]);
    }
    for(int i = 0; i < lenB; i++)
    {
        strcpy(B[i] , arr[mid + 1 + i]);
    }
    int i = 0, j = 0, k = head;
    while(i < lenA && j < lenB)
    {
        if(strcmp(A[i], B[j])<0)
        {
            strcpy(arr[k], A[i]);
            i++;
        }
        else
        {
            strcpy(arr[k], B[j]);
            j++;
        }
        k++;
    }
    while(i < lenA)
    {
        strcpy(arr[k], A[i]);
        i++;
        k++;
    }
    while(j < lenB)
    {
        strcpy(arr[k], B[j]);
        j++;
        k++;
    }
}
void mergesort1(int *arr, int head, int tail)
{
    if(head < tail)
    {
        int mid = (head + tail) / 2;
        mergesort1(arr, head, mid);
        mergesort1(arr, mid+1, tail);
        merge1(arr, head, mid, tail);
    }
}
void mergesort2(char **arr, int head, int tail)
{
    if(head < tail)
    {
        int mid = (head + tail) / 2;
        mergesort2(arr, head, mid);
        mergesort2(arr, mid+1, tail);
        merge2(arr, head, mid, tail);
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
    mergesort1(numstr, 0, 1000000-1);
    gettimeofday(&tv2, NULL);
    //for (int i=0; i < 1000000; i++)
        //printf("%d\n", numstr[i]);
    //printf("\n");
    double diff = (tv2.tv_sec - tv1.tv_sec) + (tv2.tv_usec - tv1.tv_usec) / 1000000.0;
    printf("%fs\n", diff);
    fclose(file1);

    gettimeofday(&tv3, NULL);
    mergesort2(arrstr, 0, 1000000-1);
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
