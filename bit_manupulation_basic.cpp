#include<iostream>

using namespace std;

int getBit(int n, int i)
{
    return ((n & (1<<i)) != 0); // 001<<2 = 100, 101 & 100 == 100
}

int setBit(int n, int i)
{
    return (n | (1<<i)); // 001<<1 = 010, 101 | 010 = 111
}

int clearBit(int n, int i)
{
    int com = ~(1<<i);
    return (n & com); // 001<<0 = 001, ~001 = 110, 101 & 110 = 100
}

int updateBit(int n, int i, int value)
{
    n = (n&(~(1<<i)));
    return (n | (value<<i));

    // if(getBit(n, i) && value == 0)
    // {
    //     return clearBit(n, i);
    // }
    // else if (!getBit(n, i) && value == 1)
    // {
    //     return setBit(n, i);
    // }

    // return n;
}

int main()
{
    cout<< getBit(5, 2) <<endl;
    cout<< setBit(5, 1) <<endl;
    cout<< clearBit(5, 0) <<endl;
    cout<< updateBit(5, 1, 1) <<endl;
}