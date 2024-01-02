#include<stdio.h>
#include<stdlib.h>
// 多项式相乘 相加
// 数据结构设计
typedef struct PolyNode *Polynomial;
struct PolyNode
{
    int coef;
    int expon;
    Polynomial link;
};

Polynomial ReadPoly();
void Attach(int c, int e, Polynomial* pRear);
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial Mult(Polynomial P1, Polynomial P2);
void PrintPoly(Polynomial P);
int Compare(int a, int b);

// 程序框架搭建
int main()
{
    Polynomial P1, P2, PP, PS;

    P1 = ReadPoly();
    P2 = ReadPoly();
    PP = Mult(P1, P2);
    PrintPoly(PP);
    PS = Add(P1, P2);
    PrintPoly(PS);

    return 0;
}

// 如何读入多项式

Polynomial ReadPoly()
{
    Polynomial p, rear, t;
    int c, e, n;

    scanf("%d", &n);
    p = (Polynomial)malloc(sizeof(Polynomial));
//    p = (Polynomial)malloc(sizeof(struct PolyNode));
    p->link = NULL;
    rear = p;
    while (n--)
    {
        scanf("%d %d", &c, &e);
        Attach(c, e, &rear);//将当前输入项插入多项式尾部
    }
    t = p;
    p = p->link;
    free(t);
    return p;
}

void Attach(int c, int e, Polynomial* pRear)
{
    Polynomial P;

    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c; // 对新结点赋值
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P; // 修改pRear的值
}

int Compare(int a, int b)
{
    if (a > b)    return 1;
    else if (a < b)   return -1;
    else    return 0;
}

// 多项式相加
Polynomial Add(Polynomial P1, Polynomial P2)
{
    Polynomial P, Rear, t, t1, t2;
    t1 = P1; t2 = P2;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    while (t1 && t2)
    {
        switch (Compare(t1->expon, t2->expon))
        {
            case 1:
                Attach(t1->coef, t1->expon, &Rear);
                t1 = t1->link;
                break;
            case -1:
                Attach(t2->coef, t2->expon, &Rear);
                t2 = t2->link;
                break;
            case 0:
                if (t1->coef + t2->coef)   Attach(t1->coef + t2->coef, t1->expon, &Rear);
                t1 = t1->link;
                t2 = t2->link;
                break;
        }
    }
    //注意细心，不要把遍历写到前面那个括号去了
    for (; t1; t1 = t1->link) Attach(t1->coef, t1->expon, &Rear);
    for (; t2; t2 = t2->link) Attach(t2->coef, t2->expon, &Rear);
    Rear->link = NULL;
    t = P;
    P = P->link;
    free(t);
    return P;
}

// 多项式相乘
Polynomial Mult(Polynomial P1, Polynomial P2)
{
    Polynomial P, Rear, t1, t2, t;
    int c, e;

    if (!P1 || !P2)  return NULL;

    t1 = P1;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;

    while (t1)
    {
        t2 = P2; Rear = P;//必须在里面，每个数字都要循环遍历
        while (t2)
        {
            e = t1->expon + t2->expon;
            c = t1->coef * t2->coef;
            while (Rear->link!=NULL && Rear->link->expon > e)
                Rear = Rear->link;
            if (Rear->link!=NULL && Rear->link->expon == e)
            {   // 指数的系数相等
                if (Rear->link->coef + c!=0)
                    Rear->link->coef += c;
                else {
                    Rear->link = Rear->link->link;
                }
            }
            else    // 指数的系数不相等
            {
                t = (Polynomial)malloc(sizeof(struct PolyNode));
                t->coef = c;
                t->expon = e;
                t->link = Rear->link;
                Rear->link = t;
                Rear = t;//Rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }

    P = P->link;
    free(t2);
    free(t1);
    return P;
}

// 如何将多项式输出
void PrintPoly(Polynomial P)
{
    int flag = 0;   // 辅助调整输出格式用
    if (!P)
    {
        printf("0 0\n");
        return;
    }

    while (P)
    {
        if (flag==0)   flag = 1;
        else    printf(" ");
        printf("%d %d", P->coef, P->expon);
        P = P->link;
    }
    printf("\n");
}
