#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"MaxSubseqSum.h"
clock_t start = 0, stop = 0;
double duration = 0;
int main(void)
{
    int i = 0;
    int max_sum = 0;
    int length;
    int *List = NULL;
    int modle =0;
    printf("choose your modle \n 1:-2 11 -4 13 -5 -2 \n 2:102 \n 3:103 \n 4:104 \n 5:105 \n");
    scanf("%d",&modle);
    switch (modle) {
        case 1:
            length=6;
            List = (int *)malloc(sizeof(int)*length);
            List[0]=-2;
            List[1]=11;
            List[2]=-4;
            List[3]=13;
            List[4]=-5;
            List[5]=-2;
            length=6;
            for(i=0;i<6;i++){
                printf(" %d ",List[i]);
            }
            break ;
        case 2:
            length =102;
            List = (int *)malloc(sizeof(int)*length);
            srand(time(NULL));
            for (i = 0; i < length; i++)
            {
                List[i] =rand() % length-length/2;
                /*printf("%d ", List[i]);*/
                printf(" %d ",List[i]);
            }
            printf("\n");
            break ;
        case 3:
            length =103;
            List = (int *)malloc(sizeof(int)*length);
            srand(time(NULL));
            for (i = 0; i < length; i++)
            {
                List[i] =rand() % length-length/2;
                /*printf("%d ", List[i]);*/
                printf(" %d ",List[i]);
            }
            printf("\n");
            break ;
        case 4:
            length =104;
            List = (int *)malloc(sizeof(int)*length);
            srand(time(NULL));
            for (i = 0; i < length; i++)
            {
                List[i] =rand() % length-length/2;
                /*printf("%d ", List[i]);*/
                printf(" %d ",List[i]);
            }
            printf("\n");
            break ;
        case 5:
            length =105;
            List = (int *)malloc(sizeof(int)*length);
            srand(time(NULL));
            for (i = 0; i < length; i++)
            {
                List[i] =rand() % length-length/2;
                /*printf("%d ", List[i]);*/
                printf(" %d ",List[i]);
            }
            printf("\n");
            break ;
    }
    //算法一所用的时间
    start = clock();
    for (i = 0; i < 10; i++)
    {
        max_sum = MaxSubseqSum1(List, length);
    }
    stop = clock();
    duration = (double)(stop - start) / CLK_TCK/10;
    printf("\nfirst time is %lf\nmax time is %d\n\n", duration,max_sum);

    //算法二所用的时间
    start = clock();
    for (i = 0; i < 10; i++)
    {
        max_sum = MaxSubseqSum2(List, length);
    }
    stop = clock();
    duration = (double)(stop - start) / CLK_TCK / 10;
    printf("second time is %lf\nmax time is %d\n\n", duration, max_sum);

    //算法三所用的时间
    start = clock();
    for (i = 0; i < 10; i++)
    {
        max_sum = MaxSubseqSum3(List, length);
    }
    stop = clock();
    duration = (double)(stop - start) / CLK_TCK / 10;
    printf("third time is %lf\nmax time is %d\n\n", duration, max_sum);

    //算法四所用的时间
    start = clock();
    for (i = 0; i < 10; i++)
    {
        max_sum = MaxSubseqSum4(List, length);
    }
    stop = clock();
    duration = (double)(stop - start) / CLK_TCK / 10;
    printf("forth time is %lf\nmax time is %d\n\n", duration, max_sum);

    free(List);
    return 0;
}
