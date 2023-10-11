//wap to calculate the sum of digits of a numbrer using function 
#include <stdio.h>

int sum(int n);

int main()
{
    int n, s;
    printf("Enter a number: ");
    scanf("%d", &n);
    s = sum(n);
    printf("Sum of digits: %d", s);
    return 0;
}

int sum(int n)
{
    int s = 0;
    printf("value of n is : %d\n",n);
    while (n > 0)  
    
    {
        s += n % 10;
        n =n/ 10;
    }
    printf("value of n is : %d\n",n);
    return s;
}
