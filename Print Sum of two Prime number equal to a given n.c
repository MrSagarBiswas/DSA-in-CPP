// Online C compiler to run C program online
#include <stdio.h>

int isPrime(int n){
    
    int f = 0;
    for(int i=2; i<n; i++){
        if( n%i == 0 ){
            f=1;
            break;
        }
    }
     return f;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for(int a=1; a<n/2; a++ ){
        if(isPrime(a) == 0){
            if(isPrime(n-a) == 0){
                printf("%d + %d = %d \n", a, n-a, n);
            }
        }
    }
    
    return 0;
}