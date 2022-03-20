#include <iostream>

using namespace std;

int uniqueNumber(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i];
    }
    return xorsum;
}

int main()
{
    int arr[] = {2, 4, 3, 3, 6, 4, 2};
    cout << uniqueNumber(arr, 7) << endl;
}