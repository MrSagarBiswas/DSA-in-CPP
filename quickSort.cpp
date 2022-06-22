#include <iostream>
using namespace std;

void replace(int& a, int& b){
    a = b + a;
    b = a - b;
    a = a - b;
}

void quickSort(int a[], int start, int end){
    if(start>=end){
        return;
    }

    int count = start;
    for(int i=1; i<=end; i++){
        if(a[i] < a[start]){
            count++;
        }
    }

    //Replace Element
    replace(a[start], a[count]);

    int rightIndex = count + 1;
    for(int leftIndex = start; leftIndex < count; leftIndex++){
        if(a[leftIndex] >= a[count]){
            for (; rightIndex <= end; rightIndex++){
                if(a[rightIndex] <= a[count]){
                    replace(a[rightIndex], a[leftIndex]);
                    break;
                }
            }
        }
    }

    quickSort(a, start, count - 1);
    quickSort(a, count + 1, end);
}

int main(){
	int a[] = {10, 7, 8, 9, 1, 5};
	quickSort(a, 0, 5);
	for(int i=0; i<6; i++){
		cout<<a[i]<<" ";
	}
}