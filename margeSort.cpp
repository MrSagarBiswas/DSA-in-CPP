#include<iostream>
using namespace std;

void marge(int a[], int start, int mid, int end){
    int leftArrSize = mid - start + 1;
    int rightArrSize = end - mid;

    //Create temp array in heap memory.
    int* sortedArr = new int[leftArrSize + rightArrSize];

    //inserting elements into sortedArr in increasing order.
    int leftArrIndex = 0;
    int rightArrIndex = 0;
    int i = 0;
    while(leftArrIndex < leftArrSize && rightArrIndex < rightArrSize){
        if(a[start + leftArrIndex]<a[mid + 1 + rightArrIndex]){
            sortedArr[i++] = a[start + leftArrIndex];
            leftArrIndex++;
        } else {
            sortedArr[i++] = a[mid + 1 + rightArrIndex];
            rightArrIndex++;
        }
    }

    //inserting left elements of left array.
    while (leftArrIndex < leftArrSize)
    {
        sortedArr[i++] = a[start + leftArrIndex];
        leftArrIndex++;
    }

    //inserting left elements of right array.
    while (rightArrIndex < rightArrSize)
    {
        sortedArr[i++] = a[mid + 1 + rightArrIndex];
        rightArrIndex++;
    }
    
    //Copying sortedArr into main array from start index to end index;
    for(int i=0; i<leftArrSize + rightArrSize; i++){
        a[start + i] = sortedArr[i];
    }
}

void margeSort(int a[], int start, int end){
    if(start>=end){
        return;
    }

    //Dividing into two part and applying the same margeSort algorithm.
    int mid = (start+end)/2;
    margeSort(a, start, mid);
    margeSort(a, mid+1, end);

    //Sort those two array and Marge those two sorted Array in sorted format.
    marge(a, start, mid, end);
}

int main()
{
    int a[] = {5, 9, 6, 3, 12, 1};
    margeSort(a, 0, 5);
    for(auto i=0; i<6; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}