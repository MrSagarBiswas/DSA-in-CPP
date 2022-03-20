#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s = "aaabbzjhgfyudbbx";
    int arr[26];

    // Assign 0 to every array Element
    for(int i=0; i<26; i++)
    {
        arr[i] = 0 ;
    }

    // Counting Every character 
    for(int i=0; i<s.length(); i++)
    {
        arr[s[i]-97]++;
    }

    int maxChar = 0;
    char ans = '\0';
    for(int i=0; i<26; i++)
    {
        if (maxChar < arr[i])
        {
            ans = 'a' + i;
            maxChar = arr[i];
        }
    }

    cout<<maxChar<<endl;
    cout<<ans<<endl;
}