#include <stdio.h>

void merge(int min , int mid, int max, int a[])
{
	int i = min;
	int j = mid + 1;
	int k = min;

	int temp[max+1];		// max - the index of the last element, not the number of elements

	while(i <= mid && j <= max)
	{
		if(a[i]<=a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while(i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while(j <= max)
	{
		temp[k] = a[j];
		k++;
		j++;
	}

	for(i=min; i<max+1; i++)		// same goes here like above 
	{
		a[i] = temp[i];
	}
}

void devide(int min, int max, int a[])
{
	int mid;
	if(min<max)
	{	
		mid = (min+max)/2;
		devide(min, mid, a);
		devide(mid+1, max, a);
		merge(min, mid, max, a);
	}
	else
	{
		return;
	}
}

int main() 
{
	int n, i;
	printf("How many elements does your array have? ");
	scanf(" %d", &n);

	int a[n];
	printf("Insert every element: ");
	for(i=0; i<n; i++)
	{
		scanf(" %d", &a[i]);
	} 

	printf("Unsorted array: \n");
	for(i=0; i<n; i++)
	{
		printf(" %d", a[i]);
	}

	printf("\n");
	devide(0, n - 1, a);

	printf("Sorted array: \n");
	for(i=0; i<n; i++)
	{
		printf(" %d", a[i]);
	}
}