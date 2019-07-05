#include <stdio.h>

void insertion(int n, int arr[]);
// The function that executes selection sort.

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
	insertion(n, arr);
    // The call for the algorithm.

	printf("Sorted array: \n");
	for(i=0; i<n; i++)
	{
		printf(" %d", arr[i]);
	}
    return 0;
}

void insertion(int n, int arr[]) 
{
    int i, j;

    for(i = 1; i < n; i++)
    {
        for(j = i; j > 0; j--)
        {
            if(arr[j] < arr[j-1])
            {
                arr[j] = arr[j] + arr[j-1];
                arr[j-1] = arr[j] - arr[j-1];
                arr[j] = arr[j] - arr[j-1];
            }
            else
            {
                break;
            }
        }    
    }
}