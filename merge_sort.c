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
	// The first index of the first branch of the unsorted array.
	int j = mid + 1;
	// The first index of the second branch of the unsorted array.
	int k = min;
	// The first index of the temporal array.

	int temp[max+1];
	// The temporal array, which has max+1 elements, because max - the last index of the
	// unsorted array, it starts from 0 => that the number of elements is with one unit bigger. 

	while(i <= mid && j <= max) 
	// It will execute until one array runs out of numbers.
	{
		if(arr[i]<=arr[j])
		// Checks which element is smaller.
		{
			// If arr[i] is smaller, the temporal array will hold that value in the k slot,
			// which increments itself in every loop.
			temp[k] = arr[i]; 
			k++;
			i++;
			// i is incremented to go to the next element of the first branch.
		}
		else
		{
			// The same goes here but when arr[j] is smaller.
			temp[k] = arr[j];
			k++;
			j++;
			// j is incremented to go to the next element of the second branch.
		}
	}

	// Because the array is split in half, it cannot have more than one numbers in difference,
	// meaning that just one of the following loops will be executed and just for one cycle.
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

	// Since the sorted values are saved in the temporal array they have to be transfered in the 
	// unsorted array and avoid errors.
	for(i=min; i<max+1; i++)
	// i=min - not always does the temporal array start from the first element.
	// i<max+1 - this is the max index value that the temporal array can have. 
	{
		arr[i] = temp[i];
	}
}