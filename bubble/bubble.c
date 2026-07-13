#include <cs50.h>
#include <stdio.h>

void bubble_sort(int arr[], int n)
{
    // Repeat passes through the array
    for (int j = 0; j < n - 1; j++)
    {
        // Compare each pair of adjacent elements
        for (int i = 0; i < n - 1; i++)
        {
            // Swap if the elements are out of order
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

void print_array(int arr[], int size)
{
    // Print each element in the array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    // Array with numbers from 0 to 9 in reverse order
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array
    bubble_sort(arr, n);

    // Print the sorted array
    print_array(arr, n);

    return 0;
}
