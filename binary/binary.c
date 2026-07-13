#include <cs50.h>















bool bin_search(int value, int values[], int size)
{
    int min = 0;
    int max - size - 1;

    while(min <= max)
    {
        int middle = (min + max) / 2;
        if (value == values[middle])
        {
            return true;
        }
        if (value > values[middle])
        {
            max = middle - 1;
        }
        else
        {
            min = middle -1;
        }


    }
    return false;
}
