#include <iostream>

using namespace std;

int fib(int n)
{
    if (n == 2)
    {
        return 1;
    }
    if (n == 1)
    {
        return 0;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    cout << fib(5) << endl;
}