#include <stdio.h>

void shell(int n, int arr[]);
// The function that executes shell sort.

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
	shell(n, arr);
    // The call for the algorithm.

	printf("Sorted array: \n");
	for(i=0; i<n; i++)
	{
		printf(" %d", arr[i]);
	}
    return 0;
}

void shell(int n, int arr[]) 
{
    int i = 0, gap;
    gap = n / 2;
    
    for(i = gap; i < n; i++)
    {
        if(arr[gap] < arr[i+1] && i+1 < n)
        {
            arr[gap] = arr[gap] + arr[i+1];
            arr[i+1] = arr[gap] - arr[i+1];
            arr[gap] = arr[gap] - arr[i+1];
        }
    }

    for(i = gap+1; i < n; i++)
    {
        if(arr[i] < arr[i-gap])
        {
            arr[i-gap] = arr[i-gap] + arr[i];
            arr[i] = arr[i-gap] - arr[i];
            arr[i-gap] = arr[i-gap] - arr[i];
        }
    }

    if(arr[gap] < arr[gap-gap])
    {
        arr[gap] = arr[gap] + arr[gap-gap];
        arr[gap-gap] = arr[gap] - arr[gap-gap];
        arr[gap] = arr[gap] - arr[gap-gap];
    }

    gap = n / 4;

    for(i = gap; i < n; i++)
    {
        if(arr[i] < arr[i-1] && i-1 > 0)
        {
            arr[i] = arr[i] + arr[i-1];
            arr[i-1] = arr[i] - arr[i-1];
            arr[i] = arr[i] - arr[i-1];
        }
    }
}