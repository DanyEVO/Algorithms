#include <stdio.h>

void devide(int min, int max, int arr[]);					
// Recursive function that devides the array in smaller arrays until it has one element.
void merge(int min , int mid, int max, int arr[]);			
// The function which checks what element is greater and puts it in the rightful place.

int main() 
{
	int n, i;
	printf("How many elements does your array have? ");		
	// There is no tested limit for the array's size.
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
	// This is the call for the Recursive Function; 0 - allways the first index,
	// n-1 - allways the last index & arr - the unsorted array.

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
	// When the values of min and max are equal the function will return to the previous one.
	{	
		mid = (min+max)/2;									
		// mid - the closest centre of the array (it can have even number of elements,
		// then it will choose the smallest from the two options).
		devide(min, mid, arr);
		devide(mid+1, max, arr);
		merge(min, mid, max, arr);
		// This is the call for the merging function, which will be called for every devided array;
		// min - the first index, mid - the middle index, max - the last index & arr - the array with
		// which the function will work.
	}
	else
	{
		return; 
		// Return to the previous function and continue.
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