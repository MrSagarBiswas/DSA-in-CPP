#include <bits/stdc++.h>
using namespace std;

int ropePieces(int n, int a, int b, int c, int count=0){
    if(n==0){
        return count;
    } else if (n<0){
        return -1;
    }

    int i = ropePieces(n-a, a, b, c, count+1);
    int j = ropePieces(n-b, a, b, c, count+1);
    int k = ropePieces(n-c, a, b, c, count+1);

    return max(i, max(j, k));
}

int main()
{
    cout<<ropePieces(5, 4, 2, 6);
}