#include<stdio.h>
#include <stdlib.h>
typedef struct road{
    int value;
    int start;
    int end;
}road;

void Input_Road(road roads[],int m){
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&roads[i].start,&roads[i].end,&roads[i].value);
    }
}
void Initcity(int city[],int n){
    for(int i=0;i<n;i++){
        city[i]=0;
    }
}
int cmp(const void*p1 , const void*p2){//比较函数
    return (*(road*)p1).value - (*(road*)p2).value;
}
void sortAscending(road roads[],int m){
    qsort(roads, m, sizeof(road), cmp); //使用qsort函数对数组进行排序
}
int find(road roads[],int N,int M){
    int x[1001] = { 0 };
    int sum = 0;//记录最低费用
    x[roads[0].start] = 1;
    x[roads[0].end]=1;//最短的两个点作为开始，进行标记
    sum+=roads[0].value; // 加入路径
    int i,j;
    for (i = 2; i < N; i++) {
        for (j = 1; j < M; j++) {
            if (x[roads[j].start] && !x[roads[j].end]) {//一个点标记一个点没标记
                sum += roads[j].value;
                x[roads[j].end] = 1;
                break;
            }
            else if (!x[roads[j].start] && x[roads[j].end]) {//一个点标记一个点没标记
                sum += roads[j].value;
                x[roads[j].start] = 1;
                break;
            }
        }
        if (j == M)
            return -1;
    }
    return sum;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    road roads[m];
    int city[n];
    Initcity(city,n);
    Input_Road(roads,m);
    sortAscending(roads,m);
    int sum=find(roads,n,m);
    printf("%d",sum);
    return 0;
}