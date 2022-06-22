#include <bits/stdc++.h>
using namespace std;

void insert(int arr[], int n, int index, int value){
    for(int i=n; i>index; i--){
        arr[i]=arr[i-1];
    }
    arr[index] = value;
}

void print(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main(){
	int arr[6] = {1, 2, 3, 4, 5};
    insert(arr, 6, 5, 10);
    print(arr, 6);
}