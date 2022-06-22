#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n){
    int i=0;
    while(i<n){
        swap(arr[i++], arr[--n]);
    }
}

void print(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 19, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverse(arr, n);
    print(arr, n);
    return 0;
}