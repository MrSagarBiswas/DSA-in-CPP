#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    string n = "1367642";
    // sort(n.begin(), n.end());
    // reverse(n.begin(), n.end());
    sort(n.begin(), n.end(), greater<int>());
    cout<<n<<endl;
}