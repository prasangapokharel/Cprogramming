#include<stdio.h>
main()
{
int num[5],i;
for(i=0;i<5;i++)
{
printf("Enter array elements =");
scanf("%d",&num[i]);
}

for(i=0;i<5;i++)
{
printf("%d\t",num[i]);
}
}
