#include <stdio.h>
#include <conio.h>

int main(){
	int num,i;
	int arr[5];
	for(i=0;i<5;i++){
		printf("Enter a number");
		scanf("%d",&arr[i]);
		printf("value of array inside loop %d",arr[i]);
	}
	printf("%d",arr);
	getch();
	return 0;
	
}
