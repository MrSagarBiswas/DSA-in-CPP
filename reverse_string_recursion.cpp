#include <iostream>
#include <string>

using namespace std;

void reverse(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    reverse(s.substr(1));
    cout << s[0];
}

int main()
{
    string s = "sagar biswas";
    reverse(s);
}