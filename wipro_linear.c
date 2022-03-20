#include <stdio.h>

int main()
{
    int d, p=0;
    scanf("%d", &d);
    int u = 1, n = 0;
    for (int i = 0; i < d / 7 + 1; i++)
    {
        if(i<d/7)
        {
            n=7;
        }else
        {
            n=d%7;
        }
        p += n*(2*u+n-1)/2;
        u++;
    }

    printf("%d", p);
}