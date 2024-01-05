#include <stdio.h>

int main() {
    // 读取员工总人数
    int N;
    scanf("%d", &N);

    // 初始化数组存储每个工龄的员工个数
    int ages[51] = {0};

    // 读取每个员工的工龄，并统计每个工龄的人数
    for (int i = 0; i < N; ++i) {
        int age;
        scanf("%d", &age);
        ages[age]++;
    }

    // 输出结果
    for (int i = 0; i <= 50; ++i) {
        if (ages[i] > 0) {
            printf("%d:%d\n", i, ages[i]);
        }
    }

    return 0;
}
