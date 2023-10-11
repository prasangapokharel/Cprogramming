 #include<stdio.h>
  #include<string.h>
  #define MAX 10
  #define SIZE 50
  int main()
  {
    char name [MAX][SIZE],temp[SIZE];
    int i,j;
    
    for (i=0;i<MAX;i++)
    {
        printf("Enter name%d",i+1 );
        gets(name[i]);
    }
    
    {
        for (j=0;j<MAX-1;i++)
        {
            if (strcmpi(name[j],name[j+1])>0)
            {
                strcpy (temp,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],temp);
            }
        }
    }
    
    printf("\n After sorting......\n");
    for (i=0;i<MAX;i++)
    printf("%s\n",name[i]);

    return  0 ; 
  }
             