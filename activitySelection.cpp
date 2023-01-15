#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> v{{3, 8}, {2, 4}, {1, 3}, {10, 11}};
    int res = 0;
    for(int i=0; i<4; i++){
        int temp=v[i][0];
        v[i][0]=v[i][1];
        v[i][1]=temp;
    }
    sort(v.begin(), v.end());
    for(int i=0; i<4; i++){
        int temp=v[i][0];
        v[i][0]=v[i][1];
        v[i][1]=temp;
    }
    int previous = v[0][0];
    for (int i = 0; i < 4; i++)
    {
        if (v[i][0] >= previous)
        {
            previous = v[i][1];
            res++;
        }
    }

    cout << res;
    return 0;
}