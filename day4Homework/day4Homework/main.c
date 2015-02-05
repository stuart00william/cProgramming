//
//  main.c
//  day4Homework
//
//  Created by Stuart H on 2/5/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_ROWS 2
#define ARRAY_COLS 2

int basic2DArrayFun(void) {
    
    long cur_time;
    cur_time=time(NULL);
    srand((int)cur_time);
    
    
    int twoDArray[ARRAY_ROWS][ARRAY_COLS];
    long long sumOfAll=0;
    int nrOfElements=0;

    
    for (int i=0;i<ARRAY_ROWS;i++) {
        for (int j=0;j<ARRAY_COLS;j++) {
            twoDArray[i][j]=rand()/100000000;
            printf("%-5d",twoDArray[i][j]);
            sumOfAll+=twoDArray[i][j];
            nrOfElements++;
        }
        printf("\n");
    }
    
    int largestElement=0;
    int smallestElement=twoDArray[ARRAY_ROWS-1][ARRAY_COLS-1];
    int largest[2],smallest[2];
    int rowSum[ARRAY_ROWS]={0};
    int colSum[ARRAY_COLS]={0};
    for (int i=0;i<ARRAY_ROWS;i++) {
        for (int j=0;j<ARRAY_COLS;j++) {
            rowSum[i]+=twoDArray[i][j];
            colSum[j]+=twoDArray[i][j];
            if (twoDArray[i][j]>largestElement) {
                largestElement=twoDArray[i][j];
                largest[0]=i;
                largest[1]=j;
            }
            if (twoDArray[i][j]<smallestElement) {
                smallestElement=twoDArray[i][j];
                smallest[0]=i;
                smallest[1]=j;
            }
        }
    }


    
    
    printf("\nThe sum of all the elements is %lld\n",sumOfAll);
    printf("\nThe total number of elements is %d\n",nrOfElements);
    printf("\nThe average of all the elements is %.2f\n",(float)sumOfAll/nrOfElements);
    printf("\nThe highest element is %d at row %d col %d\n",largestElement,largest[0],largest[1]);
    printf("\nThe smallest element is %d at row %d col %d\n\n",smallestElement,smallest[0],smallest[1]);

    int maxRowSum[2]={0};
    printf("\nRow sums:\n");
    for (int i=0;i<sizeof(rowSum)/sizeof(int);i++) {
        printf("%-5d ",rowSum[i]);
        if (rowSum[i]>maxRowSum[0]) {
            maxRowSum[0]=rowSum[i];
            maxRowSum[1]=i;
        }
    }
    printf("\nThe max row sum is %d in row %d\n",maxRowSum[0],maxRowSum[1]);
    
    int maxColSum[2]={0};
    printf("\nCol sums:\n");
    for (int i=0;i<sizeof(colSum)/sizeof(int);i++) {
        printf("%-5d ",colSum[i]);
        if (rowSum[i]>maxColSum[0]) {
            maxColSum[0]=colSum[i];
            maxColSum[1]=i;
        }
    }
    printf("\nThe max row sum is %d in row %d\n\n",maxColSum[0],maxColSum[1]);

    int upperLeftLowerRight=0;
    int upperRightLowerLeft=0;
    
    for (int i=0;i<ARRAY_ROWS;i++) {
        for (int j=i;j==i;j++) {
            upperLeftLowerRight+=twoDArray[i][j];
        }
    }
    printf("The diagonal sum from upper left to lower right is %d\n",upperLeftLowerRight);
    
    
    int l=ARRAY_COLS-1;
    for (int i=0;i<ARRAY_ROWS;i++) {
        int k=0;
        for (int j=l,k=0;k==0;j--) {
            upperRightLowerLeft+=twoDArray[i][j];
            k++;
            l--;
        }
    }
    printf("The diagonal sum from upper right to lower left is %d\n",upperRightLowerLeft);

    
    
    return 0;
}




int main(int argc, const char * argv[]) {
    
    basic2DArrayFun();
    
    return 0;
}
