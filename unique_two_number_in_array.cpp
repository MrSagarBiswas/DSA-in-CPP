#include <iostream>

using namespace std;

void uniqueNumber(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i];
    }

    int pos = -1, setBit = 0;
    while (setBit != 1)
    {
        setBit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }

    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & (1 << pos)) == 0)
        {
            num1 ^= arr[i];
        }
        else
        {
            num2 ^= arr[i];
        }
    }

    cout << num1 << endl;
    cout << num2 << endl;
}

int main()
{
    int arr[] = {2, 4, 5, 3, 6, 4, 2, 3};
    uniqueNumber(arr, 8);
}