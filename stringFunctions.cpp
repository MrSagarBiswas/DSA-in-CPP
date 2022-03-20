#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "Fam", b = "ily";
    // cin>>s;
    // getline(cin, s);
    s.append(b);
    s.erase(2, 1);
    // s.clear();
    cout<<s.find("il")<<endl;
    s.insert(2, "m");
    cout<< s.substr(2, 4)<<endl;
    if(!s.empty())
        cout<<s;
}