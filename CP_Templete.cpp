#include <bits/stdc++.h>
using namespace std;

int main()
{
    int TestCases;
    cin >> TestCases;
    for (int i = 1; i <= TestCases; i++)
    {
        int N;
        cin >> N;
        int a[N];
        for(int j=0; j<N; j++) cin>>a[j];

        cout << "Case #" << i << ": ";
        for(int j=0; j<N; j++){
            int ans = -1;
             
            for(int k=0; k<N; k++){
                if(k!=j && a[k]<=2*a[j]){
                    ans = max(ans, a[k]);
                }
            }
            cout << ans << " ";
        }
        cout<<endl;
    }
}