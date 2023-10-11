#include <stdio.h>

int prime(int , int );

void check(int n)
{
    if (prime(n, 2) == 1)
        printf("%d: Prime", n);
    else
        printf("\n%d: Not Prime", n);
}

int prime(int n, int c)
{
    if (c >= n)
        return 1;
    else if (n % c == 0)
        return 0;
    else
        return prime(n, c + 1);
}

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    check(n);
    return 0;
}

