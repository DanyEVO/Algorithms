#include <stdio.h>

void merge(int min , int mid, int max, int arr[])
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

	for(i=min; i<max+1; i++)
	{
		a[i] = temp[i];
	}
}

void devide(int min, int max, int arr[])
{
	int mid;
	if(min<max)
	{	
		mid = (min+max)/2;
		devide(min, mid, arr);
		devide(mid+1, max, arr);
		merge(min, mid, max, arr);
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

	int arr[n];
	printf("Insert every element: ");
	for(i=0; i<n; i++)
	{
		scanf(" %d", &arr[i]);
	} 

	printf("Unsorted array: \n");
	for(i=0; i<n; i++)
	{
		printf(" %d", arr[i]);
	}

	printf("\n");
	devide(0, n - 1, arr);

	printf("Sorted array: \n");
	for(i=0; i<n; i++)
	{
		printf(" %d", arr[i]);
	}
}