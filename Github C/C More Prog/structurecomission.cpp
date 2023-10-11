#include<stdio.h>

struct salesperson
{
	int id;
	char name[20];
	float sales_amount;
	float commission;
};

//Function to calculate commission
float calculate_commission(float sales_amount)
{
	if(sales_amount < 1000)
		return 0;
	else if(sales_amount >= 1000 && sales_amount <= 2000)
		return (float) sales_amount * 0.1;
	else
		return (float) sales_amount * 0.2;
}

int main()
{
	struct salesperson s[10];
	int i;
	float c;
	
	//Input the details
	for(i=0; i<10; i++)
	{
		printf("\nEnter ID, Name and Sales Amount of Salesperson %d: ", i+1);
		scanf("%d %s %f", &s[i].id, s[i].name, &s[i].sales_amount);
		
		//Calculate commission
		s[i].commission = calculate_commission(s[i].sales_amount);
	}
	
	//Sorting in descending order of commission
	for(i=0; i<9; i++)
	{
		for(int j=i+1; j<10; j++)
		{
			if(s[i].commission < s[j].commission)
			{
				struct salesperson temp;
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
	
	//Display the details
	printf("\nID\tName\tSales Amount\tCommission\n");
	for(i=0; i<10; i++)
		printf("%d\t%s\t%.2f\t\t%.2f\n", s[i].id, s[i].name, s[i].sales_amount, s[i].commission);
		
	return 0;
}
