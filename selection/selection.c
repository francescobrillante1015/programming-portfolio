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


#include <cs50.h>
#include <stdio.h>

bool search(int value, int values[], int start, int end);

int main(void)
{
    // Define sorted array
    int values[] = {-1, 2, 3, 5, 7, 10, 15, 21, 32, 50};

    // Get input
    int value = get_int("Enter a number: ");

    // Define start and end values to begin searching
    int start = 0;
    int end = 9;

    // Check if input value is found
    if (search(value, values, start, end))
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not found!\n");
    }
}

bool search(int value, int values[], int start, int end)
{
    // if end before start not found
    if( end < start)
    {
        return false;
    }

    //Calculate mid point
    int midpoint(start + end) / 2;

    if(value == values[midpoint])
    {
        return true;
    }

    if(value < values[midpoint])
    {
        return search(value , values , start , midpoint - 1);
    }
    else
    {
        return search(value , values , midpoint + 1, end);
    }


}
