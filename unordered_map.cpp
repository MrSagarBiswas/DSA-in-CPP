#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> map;
    map["GFG"] = 20;
    map["Biswas"] = 40;
    map["Sagar"] = 15;
    map["Hello"] = 6;
    for(auto i=map.begin(); i != map.end(); i++){
        cout<<i->first<<" "<<i->second<<endl;
    }
    map.erase(map.begin(), map.end());
    cout<<map.count("GFG");
    return 0;
}