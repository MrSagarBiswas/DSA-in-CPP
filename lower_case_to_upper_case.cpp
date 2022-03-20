#include <iostream>
#include<algorithm>
#include <string>

using namespace std;

string uperToLower(string str)
{
    for(int i=0; i<str.size(); i++){
        if(str[i]<'a'){
            str[i] +=32;
        }
    }
    return str;
}

string lowerToUpper(string str)
{
    for(int i=0; i<str.size(); i++){
        if(str[i]>'Z'){
            str[i] -=32;
        }
    }
    return str;
}

int main()
{
    string str = "DSCCjkcsBCJxaeDKJwfc";
    cout<< uperToLower(str) <<endl;
    cout<< lowerToUpper(str) <<endl;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout<<str<<endl;
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout<<str<<endl;
    sort(str.begin(), str.end());
    cout<<str<<endl;
}