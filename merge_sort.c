#include <stdio.h>

void devide(int min, int max, int arr[]);
void merge(int min , int mid, int max, int arr[]);

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

void merge(int min , int mid, int max, int arr[])
{
	int i = min;
	int j = mid + 1;
	int k = min;

	int temp[max+1];

	while(i <= mid && j <= max)
	{
		if(arr[i]<=arr[j])
		{
			temp[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}

	while(i <= mid)
	{
		temp[k] = arr[i];
		k++;
		i++;
	}

	while(j <= max)
	{
		temp[k] = arr[j];
		k++;
		j++;
	}

	for(i=min; i<max+1; i++)
	{
		arr[i] = temp[i];
	}
}