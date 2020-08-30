#include <stdio.h>

int bsearch(int arr[], int x, int min, int max);

int main()
{
    // Given a sorted array.
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr_length = 10;


    int nr = 3; // The number we are looking for.
    printf("The number is in the %d position.", bsearch(arr, nr, 0, arr_length));

    return 0;
}

int bsearch(int arr[], int x, int min, int max)
{
    if (max > min)
    {
        int mid = min + (max - min) / 2;
        if (arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return bsearch(arr, x, min, mid - 1);

        return bsearch(arr, x, mid + 1, max);    
    }

    return -1;
}