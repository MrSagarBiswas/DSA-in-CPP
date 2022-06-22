#include<iostream>
using namespace std;

void move(int a[], int i, int n){
    for(; i<n-1; i++){
        a[i] = a[i+1];
    }
    a[i] = 0;
}

void moveZeros(int a[], int n){
    for(int i=0; i<n; i++){
        if(a[i]==0){
            for(int j=i+1; j<n; j++){
                if(a[j]!=0){
                    swap(a[i], a[j]);
                    break;
                }
            }
        }
    }
}

void moveZero(int a[], int n){
    int temp[n] = {0};
    int count = 0;
    for(int i=0; i<n; i++){
        if(a[i]!=0){
            temp[count++] = a[i];
        }
    }
    for(int i=0; i<n; i++){
        a[i] = temp[i];
    }
}

void moveZerosToEnd(int a[], int n){
    int count = 0;
    for(int i=0; i<n; i++){
        if(a[i] != 0){
            swap(a[i], a[count++]);
        }
    }
}

void print(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[] = {10, 0, 00, 0, 20, 30, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    moveZerosToEnd(arr, n);
    print(arr, n);
    return 0;
}