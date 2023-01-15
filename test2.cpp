#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s){
    int l=0, r=s.length()-1;
    while(l<r){
        if(s[l++]!=s[r--])
            return false;
    }
    return true;
}
int mx;
string longestPalindrome(string s) {
    if(mx>=s.length()){
        return "";
    }
    if(isPalindrome(s)){
        mx=s.length();
        return s;
    }
    string l = longestPalindrome(s.substr(0, s.length()-1));
    string r = longestPalindrome(s.substr(1, s.length()));
    if(l.length()>=r.length()){
        return l;
    } else {
        return r;
    }
}

int main()
{

    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;

    return 0;
}