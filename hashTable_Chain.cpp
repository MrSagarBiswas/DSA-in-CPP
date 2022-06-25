#include <bits/stdc++.h>
using namespace std;

struct hashTable {
private:
    int n;
    list<int>* table;
public:
    hashTable(int b){
        n = b;
        table = new list<int>[n];
    }
    void Insert(int val){
        table[val%n].push_back(val);
    }

    bool Search(int val){
        for(auto i: table[val%n]){
            if (i==val)
                return true;
        }
        return false;
    }

    void Delete(int val){
        table[val%n].remove(val);
    }
};

int main()
{
    hashTable hash(7);
    hash.Insert(70);
    hash.Insert(140);
    cout<<hash.Search(140);
}