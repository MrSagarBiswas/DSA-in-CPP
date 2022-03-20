#include <stdio.h>

int main()
{
    int D;
    scanf("%d", &D);

    int n1, a1, d1, p1;
    n1=D/7;
    a1=28;
    d1=7;
    p1=n1*(2*a1+(n1-1)*d1)/2;
    
    int n2, a2, d2, p2;
    n2=D%7;
    a2=D/7+1;
    d2=1;
    p2=n2*(2*a2+(n2-1)*d2)/2;

    printf("%d", p1+p2);
}