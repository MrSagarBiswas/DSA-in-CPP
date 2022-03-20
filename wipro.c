#include <stdio.h>

int main()
{
    int d, p=0;
    scanf("%d", &d);
    int u = 1, count = 0;
    for (int i = 0; i < d / 7 + 1; i++)
    {
        for (int j = 0; j < 7 && count < d; j++)
        {
            p += u + j;
            count++;
        }
        u++;
    }

    printf("%d", p);
}