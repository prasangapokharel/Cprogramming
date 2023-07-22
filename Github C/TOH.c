#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int tower(int n, char s, char d, char i){
    // int j=1;
    if (n==1)//move smallest disc from source to destination
    {
        printf("Move disk %d from %c to %c\n",n,s,d);
    }
    else{
        tower(n-1,s,i,d); //move top n-1 disk to intermediate pole eith help of destination pole.
        printf("Move disk %d from %c to %c\n",n,s,d);// move single disc from source to destination
        tower(n-1,i,d,s); // move all remaining disc from intermediate to distination with the help of source pole.
    }
    
}
int main()
{
    int n;
    printf("\nEnter the number of disk: ");
    scanf("%d",&n);
    tower(n,'S','D','I');
    return 0;
}