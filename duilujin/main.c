#include <stdio.h>
#define MaxSize 10001 
#define MinH -10001

void CreateHeap(int n); // 建堆
void InsertHeap(int e); // 元素插入堆

int minHeap[MaxSize],size; // 最小堆和堆的大小（堆中元素个数）

int main()
{
    int N,M; // N：插入元素个数 M：打印路径条数
    int i,j,index;
    scanf("%d %d",&N,&M);
    CreateHeap(N); // 建立最小堆
    for(i = 0;i < M;i ++) {
        scanf("%d",&index);
        for(j = index;j > 1;j /= 2)
            printf("%d ",minHeap[j]);
        printf("%d\n",minHeap[j]);
    }
}

void CreateHeap(int n) // n是堆的元素个数
{
    int i,el;
    size = 0; // 先建个空堆
    minHeap[0] = MinH; // 设置岗哨
    for(i = 0;i < n;i ++) {
        scanf("%d",&el);
        InsertHeap(el);
    }
}

/*
【思路】
插入元素的位置起初为size + 1，但是为了保证是最小堆，要进行调整，调整的策略就是向上层（父结点）比较，如果上层元素
比该元素大就把上层元素换下来，逐层向上比较，直到不能满足父结点比插入元素大时，此时i指向的位置就是应该插入的位置
*/
void InsertHeap(int e) // e是要插入堆中的元素
{
    int i;
    for(i = ++ size;minHeap[i / 2] > e;i /= 2) {
        minHeap[i] = minHeap[i / 2]; // 只要父结点比要插入的元素大，就把父结点换下来
    }
    minHeap[i] = e;
}
