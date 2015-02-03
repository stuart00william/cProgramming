//
//  main.c
//  day2Homework
//
//  Created by Stuart H on 2/3/15.
//

#include <stdio.h>

int questionEleven(void)
{
    int inputInt;
    int ones;
    int sum=0;
    
    printf("Please enter an integer: ");
    scanf("%d",&inputInt);
    
    while(inputInt!=0)
    {
        ones=inputInt%10;
        sum+=ones;
        
        inputInt/=10;
    }
    
    printf("the sum of that integer is %d\n",sum);
    
    
    return 0;
    
}

int funWithLoops(void)
{
    printf("\n\nPart 1:\n\n");
    printf("  int  |  Sum\n");
    printf("---------------\n");
    
    int i;
    int sum=0;
    
    for (i=0;i<=10;i++)
    {
        sum+=i*i;
        printf("%4d   |%5d  |\n",i,sum);
    }
    
    
//----------------------------------------------
    
    printf("\n\nPart Two:\n\n");
    printf("  int  |  Sum\n");
    printf("---------------\n");
    
    sum=0;
    
    for(i=0;i<10;i++)
    {
        sum+=i*(i+1);
        printf("%4d   |%5d  |\n",i,sum);
    }
    

//----------------------------------------------

    printf("\n\nPart Three:\n\n");
    printf("  int  |      Sum\n");
    printf("----------------------\n");
    
    sum=0;
    
    for (int i = 1; i <= 10; i++)
    {
        int product  = 1;
        for (int j = 0; j < i; j++)
            product *= i;
        sum += product;
        printf("%4d   |%12d  |\n",i,sum);
    }
    
    
//----------------------------------------------

    printf("\n\nPart Three:\n\n");
    printf("  int  |      Sum\n");
    printf("----------------------\n");

    
    sum=0;
    int count=0;
    
    while(sum<=1000000)
    {
        printf("%4d   |%12d  |\n",count,sum);
        sum+=count+1;
        count++;
        
    }
    
    
    return 0;
}
    
int nestedLoops(void)
{

    int i,j,k;

//PART 1
    for (i=1;i<=4;i++)
    {
        for (j=i+1,k=1;k<=5;j++)
        {
            printf("%d",j);
            k++;
        }
        printf("\n");
    }
    printf("\n\n");
    
//PART 2
    for (i=1;i<=5;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d ",i);
        }
        printf("\n");
    }
    printf("\n\n");
    
//PART 3
    for (i=0;i<5;i++)
    {
        printf("%d ",i);
        for (j=0;j<=i;j++)
        {
            printf("%d ",j);
            for (k=j-1;k<=j;k++)
            {
                printf("%d ",k);        // ARGHHHHHH
            }
            
        }
        printf("\n");
    }
    printf("\n\n");
    
    
    
//PART 4

    
    for (i=1;i<=4;i++)
    {
        for (j=i;j<5;j++)
        {
            printf("%d",i+j);
        }
        printf("\n");
    }
    printf("\n\n");
    
    return 0;
}

int enumeration(void)
{
    enum shapes
    {
        circle,
        square,
        rectangle,
        triangle
    };
    char selectedShape[10];
    int validSelection=0;
    
    enum shapes usersShape;
    
    printf("Please select a shape from this list:\n");
    printf("Circle:    0\n");
    printf("Square:    1\n");
    printf("Triangle:  2\n");
    printf("Rectangle: 3\n");
    scanf("%i",&usersShape);
    
    switch (usersShape)
    {
        case circle:
            strcpy(selectedShape,"Circle");
            validSelection=1;
            break;
        
        case square:
            strcpy(selectedShape,"Square");
            validSelection=1;
            break;
            
        case triangle:
            strcpy(selectedShape,"Triangle");
            validSelection=1;
            break;
            
        case rectangle:
            strcpy(selectedShape,"Rectangle");
            validSelection=1;
            break;
        
        default:
            printf("Bad Selection\n");
            break;
    }
    
    if(validSelection!=0)
    {
        printf("You selected %s\n\n",selectedShape);
    }
    
    
    return 0;
}

int simpleForLoops(void)
{
    int starting,stopping,incrementing;
    int sum=0;
    
    printf("Please enter a starting number: ");
    scanf("%d",&starting);
    printf("Please enter a stopping number: ");
    scanf("%d",&stopping);
    printf("Please enter an increment: ");
    scanf("%d",&incrementing);
    
    printf("\n\n  i  |  sum\n");
    printf("---------------\n");
    
    for (int i=starting;i<=stopping;i+=incrementing)
    {
        sum+=i;
        printf("%3d  |%4d\n",i,sum);
    }
    
    printf("\n\nThe final sum is %d\n\n",sum);
    
    return 0;
}


int main(int argc, const char * argv[]) {
    
    //questionEleven();
    //funWithLoops();
    //nestedLoops();
    //enumeration();
    simpleForLoops();
    
    return 0;
}
