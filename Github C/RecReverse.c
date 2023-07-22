//program to reverse a number using recurtion.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int rev(int n){
    int m;
    char sn1[20], sn2[20];
    if (n < 10)
    {
        return n;
    }
    else{
        itoa(n%10,sn1,10);     //get last digit and store into sn1 string variable
        m = rev(n/10);        //reverse the remaining digit number.
        itoa(m,sn2,10);      //covert into string 
        strcat(sn1,sn2);    //concatenate sn1 and sn2
        n = atoi(sn1);     // convert string to number
        return n;         // return reversed number.
        // return (n%10) * 10 + rev(n/10);
    }
    
}
int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    printf("\nThe reverse of %d is %d",n,rev(n));
    return 0;
}