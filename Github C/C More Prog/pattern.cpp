#include <stdio.h>

int main()
{
    int i, j;
    
    for(i=0; i<5; i++)
    {
        for(j=0; j<=i; j++)
        {
            printf(" ");
        }
        for(j=0; j<5-i; j++)
        {
            printf("%d ", 1-j%2);
        }
        printf("\n");
    }
    
    return 0;
}
