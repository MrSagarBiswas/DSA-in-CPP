#include<iostream>
#include<vector>
using namespace std;

class myHash{
public:
    int cap, size = 0;
    vector<int> bag;
    myHash(int n){
        cap = n;
        vector<int> a(cap, -1);
        bag = a;
    }

    int hash(int val){
        return val%cap;
    }

    bool insert(int val){
        int key = hash(val);
        if(size==cap)
            return false;
        while(bag[key] != -1 && bag[key] != -2 && bag[key] != val)
            key = (key + 1)%cap;
        if(bag[key] == val)
            return false;
        bag[key] = val;
        size++;
        return true;
    }

    bool search(int val){
        int key = hash(val);
        int i=key+1;
        while(bag[i] != -1){
            if(bag[i]==val)
                return true;
            i = (i+1)%cap;
            if(i == key){
                return false;
            }
        }
        return false;
    }

    bool erase(int val){
        int key = hash(val);
        int i = key;
        while(bag[i] != -1){
                if(bag[i]==val){
                size--;
                bag[i] = -2;
                return true;
            }
            i=(i+1)%cap;
            if(i==key){
            return false;
            }
        }
        return false;
    }

    void display(){
        for(int i=0; i<cap; i++)
            cout<<bag[i]<<" ";
    }
};

int main()
{
    myHash hash(7);
    hash.insert(70);
    hash.insert(71);
    hash.insert(77);
    hash.erase(71);
    hash.display();
    cout<<endl;
    cout<<endl;
    cout<<hash.search(71)<<endl;
    cout<<hash.search(77)<<endl;
    return 0;
}