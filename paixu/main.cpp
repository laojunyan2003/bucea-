#include <stdio.h>
#include <stdlib.h>

// 比较函数，用于传递给qsort进行排序
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // 读取输入数据
    int N;
    scanf("%d", &N);

    int *numbers = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        scanf("%d", &numbers[i]);
    }

    // 使用qsort进行排序
    qsort(numbers, N, sizeof(int), compare);

    // 输出结果
    for (int i = 0; i < N; ++i) {
        printf("%d", numbers[i]);
        if (i < N - 1) {
            printf(" ");
        }
    }

    // 释放动态分配的内存
    free(numbers);

    return 0;
}
