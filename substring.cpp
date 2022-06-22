#include<iostream>
#include<string.h>
using namespace std;

void substring(string str, int i = 0, string curr = ""){
    if(i==str.length()){
        cout<<curr<<endl;
        return;
    }
    substring(str, i+1, curr);
    substring(str, i+1, curr+str[i]);
}

int main()
{
    substring("ABC");
    return 0;
}