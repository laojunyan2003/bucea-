//
// Created by pinkykiller on 2024-01-02.
//

#ifndef ZUIDAZILIE_MAXSUBSEQSUM_H
#define ZUIDAZILIE_MAXSUBSEQSUM_H
int MaxSubseqSum4(int *List, int length)
{
    int max_sum = 0,sum=0;
    int i = 0;

    for (i = 0; i < length; i++)
    {
        //向右累加
        sum += List[i];

        //发现更大的和则更新当前结果
        if (sum > max_sum)
        {
            max_sum = sum;
        }
        //如果当前子列和为负则不可能使后面的部分和增大，抛弃之
        if (sum < 0)
        {
            sum = 0;
        }
    }

    return max_sum;
}
int FindMidSum(int *List, int length1, int length2)
{
    int mid_left_max_sum = 0,mid_right_max_sum = 0,sum=0;
    int i = 0;

    //求出左半数列中 包含左半数列最右元素的 所有子列中 和最大的一个
    mid_left_max_sum = List[length1 - 1];
    for (i = length1 - 1; i >= 0; i--)
    {
        sum += List[i];
        if (sum > mid_left_max_sum)
        {
            mid_left_max_sum = sum;
        }
    }
    //求出右半数列中 包含右半数列最左元素的 所有子列中 和最大的一个
    sum = 0;
    mid_right_max_sum = List[length1];
    for (i = length1; i < length2+length1; i++)
    {
        sum += List[i];
        if (sum > mid_right_max_sum)
        {
            mid_right_max_sum = sum;
        }
    }
    //返回两个最大值相加的值，即跨越左右两部分的最大子序列和
    return mid_left_max_sum + mid_right_max_sum;
}
int MaxSubseqSum3(int *List, int length)
{
    int left_sum = 0, right_sum = 0, mid_sum = 0;
    int max_sum = 0;

    if (length != 1)
    {
        //求左边子列和最大值、右边子列最大值和跨过中间位置的子列和的最大值
        //当长度为2的倍数时，左边长度和右边长度一样
        if (length % 2 == 0)
        {
            left_sum=MaxSubseqSum3(List, length / 2);
            right_sum=MaxSubseqSum3(List+length/2, length / 2);
            mid_sum=FindMidSum(List, length / 2, length / 2);
        }
            //当长度不为2的倍数时，右边长度比左边长度大1
        else
        {
            left_sum = MaxSubseqSum3(List, length / 2);
            right_sum = MaxSubseqSum3(List + length / 2, length / 2+1);
            mid_sum=FindMidSum(List, length / 2, length / 2 + 1);
        }

        //比较left_sum、right_sum、mid_sum三个数最大值，将最大值赋值给max_sum，这就是最大子列和
        max_sum = left_sum;
        if (right_sum > max_sum)
        {
            max_sum = right_sum;
        }
        if (mid_sum > max_sum)
        {
            max_sum = mid_sum;
        }

        //返回最大子列和
        return max_sum;
    }
    else
    {
        return List[0];
    }
}
int MaxSubseqSum2(int *List, int length)
{
    int i = 0, j = 0, k = 0;
    int sum = 0, max_sum = 0;

    //算出所以子列的和并选出最大一个子列和
    //i表示子列的左端
    for (i = 0; i < length; i++)
    {
        //j表示子列的右端，j>=i
        sum = 0;
        for (j = i; j < length; j++)
        {
            //以i为左端，j为右端的子列的子列和 为 以i为左端，j-1为右端的子列的子列和加上List[j]
            sum += List[j];
            //判断当前子列和与当前最大子列和大小
            if (sum > max_sum)
            {
                max_sum = sum;
            }
        }
    }
    return max_sum;
}
int MaxSubseqSum1(int *List,int length)
{
    int i = 0,j = 0,k=0;
    int sum = 0, max_sum = 0;

    //算出所以子列的和并选出最大一个子列和
    //i表示子列的左端
    for (i = 0; i < length; i++)
    {
        //j表示子列的右端，j>=i
        for (j = i; j < length; j++)
        {
            //算出以i为左端，j为右端的子列的子列和
            sum = 0;
            for (k = i; k <= j; k++)
            {
                sum += List[k];
            }
            //判断当前子列和与当前最大子列和大小
            if (sum > max_sum)
            {
                max_sum = sum;
            }
        }
    }
    return max_sum;
}

#endif //ZUIDAZILIE_MAXSUBSEQSUM_H
