#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<pair<int, int>> vp{{50, 600}, {20, 500}, {30, 400}};
    for(int i=0; i<3; i++){
        for(int j=0; j<3-i; j++){
            if(vp[i].second/vp[i].first<vp[i+1].second/vp[i+1].first){
                swap(vp[i], vp[i+1]);
            }
        }
    }

    int capacity=70;
    int value=0;
    for(int i=0; i<3; i++){
        cout<<vp[i].first<<" "<<vp[i].second<<" "<<value<<endl;
        if(capacity>=vp[i].first){
            value += vp[i].second;
            capacity -= vp[i].first;
        } else {
            value += capacity*vp[i].second/vp[i].first;
            break;
        }
    }

    cout<<value;

    return 0;
}