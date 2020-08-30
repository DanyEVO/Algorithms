#include <stdio.h>

void bubble(int n, int arr[]);
// The function that executes the bubble sort.

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
	bubble(n, arr);
    // The call for the algorithm.

	printf("Sorted array: \n");
	for(i=0; i<n; i++)
	{
		printf(" %d", arr[i]);
	}
    return 0;
}

void bubble(int n, int arr[])
{
    int i, j;

    for(i = 0; i < n - 1; i++)
    // This cycle will run until i is equal to the index of the last element.
    {
        for(j = 0; j < n - i - 1; j++)
        // This cycle will run until j is equal to the index of the last unsorted element.
        {
            if(arr[j] > arr[j + 1])
            // Checking which adjacent element is bigger.
            {
                // Swaping them.
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
            }
        }
    }        
}