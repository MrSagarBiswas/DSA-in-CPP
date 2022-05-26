#include <iostream>
#include <string>
using namespace std;

// Backtracking
void permutation(string str, int l, int r)
{
    if(l==r){
        cout<<str<<endl;
        return;
    }
    for (int i = l; i < str.length(); i++)
    {
        swap(str[l], str[i]);
        permutation(str, l+1, r);
        swap(str[l], str[i]);
    }
}

int main()
{
    string str="ABC";
    permutation(str, 0, 2);
    return 0;
}