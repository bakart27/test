#include "main.h"
#include "ll.h"
#include "bst.h"
#include "bs.h"

int make(int *str, int num)
{
    srand((unsigned) time(NULL));
    int a=0;
    for(int i=0; i<num; i++)
        str[i]=i;
    for(int i=0; i<num; i++)
    {
        a=rand()%num;
        int temp=str[i];
        str[i]=str[a];
        str[a]=temp;
    }
    return num;
}

int main(int argv, char *argc[])
{
    struct timeval tv1;
    struct timeval tv2;
    struct timeval tv3;
    struct timeval tv4;
    char line[100];
    int *numstr1=malloc(8000000);
    int *numstr2=malloc(8000000);
    int len1=0;
    int len2=0;
    int cnt=5;
    if(strcmp(argc[2],"1e4")==0)
        len1=make(numstr1,10000);
    else if(strcmp(argc[2],"1e5")==0)
        len1=make(numstr1,100000);
    else if(strcmp(argc[2],"1e6")==0)
        len1=make(numstr1,1000000);
    if(strcmp(argc[4],"1e4")==0)
        len2=make(numstr2,10000);
    else if(strcmp(argc[4],"1e5")==0)
        len2=make(numstr2,100000);
    else if(strcmp(argc[4],"1e3")==0)
        len2=make(numstr2,1000);
    while(cnt<argv)
    {
        if(strcmp(argc[cnt],"-bst")==0)
        {
            printf("bst:\n");
            int *tmp, i=0, j=0;
            BST *root=NULL;
            gettimeofday(&tv1, NULL);
            while(i<len1)
            {
                tmp=(numstr1+i);
                root=insertbst(root,tmp);
                i++;
            }
            inorder(root);
            gettimeofday(&tv2, NULL);
            double diff = (tv2.tv_sec-tv1.tv_sec) + (tv2.tv_usec-tv1.tv_usec) / 1000000.0;
            printf("building time: %fs sec\n", diff);
            gettimeofday(&tv3, NULL);
            while(j<len2)
            {
            	tmp=(numstr2+j);
                if(searchbst(root,tmp))
                	continue;
                j++;
            }
            gettimeofday(&tv4, NULL);
            diff = (tv4.tv_sec-tv3.tv_sec) + (tv4.tv_usec-tv3.tv_usec) / 1000000.0;
            printf("query time: %fs sec\n", diff);
        }
        else if(strcmp(argc[cnt],"-bs")==0)
        {
            printf("bs:\n");
            int ans[len1], ans2[len2];
            for(int i=0;i<len1;i++)
            	ans[i]=numstr1[i];
            for(int i=0;i<len2;i++)
            	ans2[i]=numstr2[i];
            gettimeofday(&tv1, NULL);
            for(int i=0;i<len1;i++)
            {
            	for(int j=0;j<len1;j++)
            	{
            		if(ans[j]>ans[j+1])
            		{
            			int temp=ans[j];
            			ans[j]=ans[j+1];
            			ans[j+1]=temp;
            		}
            	}
            }
            gettimeofday(&tv2, NULL);
            double diff = (tv2.tv_sec-tv1.tv_sec) + (tv2.tv_usec-tv1.tv_usec) / 1000000.0;
            printf("building time: %fs sec\n", diff);
            int no;
            gettimeofday(&tv3, NULL);
            for(int i=0; i<len2; i++)
            	no=binarysearch(ans, ans2[i], sizeof(ans2)/sizeof(int));
            gettimeofday(&tv4, NULL);
            diff = (tv4.tv_sec-tv3.tv_sec) + (tv4.tv_usec-tv3.tv_usec) / 1000000.0;
            printf("query time: %fs sec\n", diff);

        }
        else if(strcmp(argc[cnt],"-arr")==0)
        {
            printf("arr:\n");
            int ans[len1], ans2[len2];
            for(int i=0;i<len1;i++)
            	ans[i]=numstr1[i];
            for(int i=0;i<len2;i++)
            	ans2[i]=numstr2[i];
            gettimeofday(&tv1, NULL);
            for(int i=0;i<len1;i++)
            {
            	for(int j=0;j<len1;j++)
            	{
            		if(ans[j]>ans[j+1])
            		{
            			int temp=ans[j];
            			ans[j]=ans[j+1];
            			ans[j+1]=temp;
            		}
            	}
            }
            gettimeofday(&tv2, NULL);
            double diff = (tv2.tv_sec-tv1.tv_sec) + (tv2.tv_usec-tv1.tv_usec) / 1000000.0;
            printf("building time: %fs sec\n", diff);
            gettimeofday(&tv3, NULL);
            for(int i=0;i<len2;i++)
            {
            	for(int j=0;j<len1;j++)
            	{
            		if(ans2[i]==ans[j])
            			j=len1;
            	}
            }
            gettimeofday(&tv4, NULL);
            diff = (tv4.tv_sec-tv3.tv_sec) + (tv4.tv_usec-tv3.tv_usec) / 1000000.0;
            printf("query time: %fs sec\n", diff);
        }
        else if(strcmp(argc[cnt],"-ll")==0)
        {
            printf("ll:\n");
            int *tmp, i=0, j=0;
            struct nodell *head=NULL;
            gettimeofday(&tv1, NULL);
            while(i<len1)
            {
                tmp=(numstr1+i);
                head=insertll(head,tmp);
                i++;
            }
            gettimeofday(&tv2, NULL);
            double diff = (tv2.tv_sec-tv1.tv_sec) + (tv2.tv_usec-tv1.tv_usec) / 1000000.0;
            printf("building time: %fs sec\n", diff);
            gettimeofday(&tv3, NULL);
            while(j<len2)
            {
            	tmp=(numstr2+j);
                if(search(head,tmp))
                	continue;
                j++;
            }
            gettimeofday(&tv4, NULL);
            diff = (tv4.tv_sec-tv3.tv_sec) + (tv4.tv_usec-tv3.tv_usec) / 1000000.0;
            printf("query time: %fs sec\n", diff);
        }
        cnt++;
    }
}
