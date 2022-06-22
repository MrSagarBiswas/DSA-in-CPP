#include<bits/stdc++.h>
using namespace std;

find(int arr[], int n, int key){
    if(n==-1)
        return false;
    for(int i=0; i<=n; i++)
        if(arr[i]==key)
            return true;
    return false;
}

int removeDuplicate(int arr[], int n){
    int count = -1;
    for(int i=0; i<n; i++){
        if(count == -1 || arr[i]!=arr[count]){ //!find(arr, count, arr[i]) if array was not sorted
            arr[++count] = arr[i];
        }
    }
    return count+1;
}

void print(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[] = {10, 10, 20, 20, 20, 30, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    n = removeDuplicate(arr, n);
    print(arr, n);
    return 0;
}