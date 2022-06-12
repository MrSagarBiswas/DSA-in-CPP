#include <bits/stdc++.h>
using namespace std;

bool palindrom(long long n)
{
    string str = to_string(n);
    reverse(str.begin(), str.end());
    return str == to_string(n);
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        long long A;
        int counter = 0;
        cin >> A;
        for (long long j = 1; j <= sqrt(A); j++)
        {
            if (A % j == 0)
            {
                if (palindrom(j))
                    counter++;
                if (j != A / j && palindrom(A / j))
                    counter++;
            }
        }
        cout << "Case #" << i << ": " << counter << endl;
    }
    return 0;
}