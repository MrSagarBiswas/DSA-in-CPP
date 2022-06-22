#include <bits/stdc++.h>
using namespace std;

// int secondLargest(int arr[], int n){
//     int ans = -1, Max = arr[0];
//     for(int i=0; i<n; i++){
//         Max = max(Max, arr[i]);
//     }
//     for(int i=0; i<n; i++){
//         if(arr[i]!=Max){
//             if(ans=-1){
//                 ans=i;
//             } else if (arr[i]>arr[ans]){
//                 ans = i;
//             }
//         }
//     }
//     return ans;
// }

int secondLargest(int arr[], int n){
    int l=0, sl=-1;
    for(int i=0; i<n; i++){
        if(arr[i]>arr[l]){
            sl = l;
            l = i;
        }
        if (arr[i]<arr[l]){
            if(sl == -1 || arr[i]>arr[sl]){
                sl = i;
            }
        }
    }
    return sl;
}

int main(){
	int arr[6] = {1, 2, 3, 4, 5};
    cout<<secondLargest(arr, 5);
}