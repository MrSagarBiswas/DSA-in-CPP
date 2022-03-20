#include <iostream>

using namespace std;

int uniqueNumber(int arr[], int n)
{
    int bitSaver[64] = {0};

    for (int i = 0; i < n; i++)
    {
        int position = 0;
        while (arr[i] > 0)
        {
            bitSaver[position] += arr[i] & 1;
            arr[i] >>= 1;
            position++;
        }
    }

    int result = 0;
    for (int i = 0; i < 64; i++)
    {
        bitSaver[i] %= 3;
        result = result | (bitSaver[i] << i);
    }
    return result;
}

int main()
{
    int arr[] = {2, 2, 2, 3, 3, 3, 10, 5, 5, 5};
    cout << uniqueNumber(arr, 10) << endl;
}