#include <stdio.h>

#define SIZE 10

void selection_sort(int arr[], int size);
void print_array(int arr[], int size);

int main(void)
{
    int arr[] = {1, 8, 4, 6, 0, 3, 5, 2, 7, 9};
    selection_sort(arr, SIZE);
    print_array(arr, SIZE);
}

void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min;
        for (int j = i; j < size - 1; j++)
        {
            if (j == i)
            {
                min = j;
            }
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int tmpbuf = arr[min];
        arr[min] = arr[i];
        arr[i] = tmpbuf;
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}
