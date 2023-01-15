#include <bits/stdc++.h>
using namespace std;

void TH(int n, char A='A', char B='B', char C='C'){
    if(n==0){
        return;
    }

    TH(n-1, A, C, B);
    cout<<"Move "<<n<<" Disk from "<<A<<" to "<<C<<endl;
    TH(n-1, B, A, C);
}

int main()
{
    TH(2);
}