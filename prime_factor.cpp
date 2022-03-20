#include <iostream>

using namespace std;

void primeFactor(int n)
{
    int spf[100];
    for (int i = 2; i < 100; i++)
    {
        spf[i] = i;
    }

    for (int i = 2; i < 100; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < 100; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }

    while (n != 1)
    {
        cout << spf[n] << " ";
        n = n / spf[n];
    }
}

int main()
{
    int n;
    cin>>n;
    primeFactor(n);
}