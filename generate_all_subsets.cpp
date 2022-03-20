#include<iostream>
#include<math.h>

using namespace std;

int generateAllSubsets(int arr[], int n)
{
    for(int i=0; i<(1<<n); i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i & (1<<j))
                cout<< arr[j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = 3;
    generateAllSubsets(arr, n);
}