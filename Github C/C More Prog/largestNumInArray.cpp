#include <stdio.h>
#include <conio.h>

int main(){
	
	int i,max=0;
	int arr[5];
	int answer=1;
//	printf("Size of array %d",sizeof(arr));
//	printf("Size of int %d",sizeof(int));

	for(i=0;i<5;i++){
		printf("Enter a number");
		scanf("%d",&arr[i]);
		printf("DO you want to continue(y[1]/n[0]");
		scanf(" %d",&answer);
		
		if( answer==1)
		{
			printf("Exited");
			break;
		}else{
			continue;
		}
//		printf("character %c",chr);
		
		printf("value of array inside loop %d",arr[i]);
	}
	for(i=0;i<5;i++)
	
	{
		printf("%d",arr[i]);
		if(max < arr[i]){
			max = arr[i];
//			printf("Max value inside if condition",max);
		
		}
	}
	printf("Largest value in the array=%d",max);
	return 0 ; 
	
}
