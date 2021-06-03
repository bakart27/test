#include "main.h"
#include "bs.h"

int binarysearch(int *data, int search, int n)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(data[mid]==search)
			return mid;
		else if(data[mid]>search)
			high=mid-1;
		else if(data[mid]<search)
			low=mid+1;
	}
	return -1;
}
