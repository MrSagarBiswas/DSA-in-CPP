#include<iostream>
#include<algorithm>
using namespace std;

int minCoin1(int n){
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }
    int a = 1+minCoin1(n-10);
    if(a>0) return a;
    int b = 1+minCoin1(n-5);
    if(b>0) return b;
    int c = 1+minCoin1(n-2);
    if(c>0) return c;
    int d = 1+minCoin1(n-1);
    return d;
}

int minCoin(int coins[], int n, int amount){
    sort(coins, coins+4);
    reverse(coins, coins+4);
    int res=0;
    for(int i=0; i<n; i++){
        if(coins[i]<=amount){
            int c = amount/coins[i];
            res += c;
            amount -= c*coins[i];
        }
        if(amount==0) {
            break;
        }
    }
    return res;
}

int main()
{
    int amount;
    cin>>amount;
    cout<<minCoin1(amount)<<endl;

    int coins[] = {10, 5, 2, 1};
    cout<<minCoin(coins, 4, amount);

    return 0;
}