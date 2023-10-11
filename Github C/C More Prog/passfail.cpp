        #include<stdio.h>
        int main()
        {
            int marks[5];
            int i;
            printf("Enter marks of 5 subjects:\t");
            for(i=0; i<5; i++)
            {
                scanf("%d",&marks[i]);
            }
            for(i=0; i<5; i++)
            {
                if(marks[i]>40)
                {
                    printf("Pass\n");
                }
                else
                {
                    printf("Fail\n");
                }
            }
            return 0;
        }
