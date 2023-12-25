#include<stdio.h>
#include<conio.h>
void main (){
	int n,i,j,a[20],temp;

	
printf("enter array element");
scanf("%d",&n);
for (i=0;i<n;i++)
{
	printf("\n enter element %d : ",i+1);
	scanf("%d",&a[i]);
	
	
}

for (i=0;i<n;i++)
{
	for (j=0;j<n;j++)
	
	if(a[i]>a[j])
	{
	
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
}
printf("Dessending Order...\n");	

	for (i=0;i<n;i++)
	{
	
	printf("%d",a[i]);
}

}
