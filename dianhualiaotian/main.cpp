#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXNUMBER pow(10,12)

typedef long long int EleType;
typedef struct HashEntry Cell;
struct HashEntry
{
    EleType Data;
    int InputTime;
};

typedef struct TblNode *HashTable;
struct TblNode
{
    int TableSize;
    Cell *Cells;
};

HashTable CreateTable(int N)
{
    HashTable H = (HashTable)malloc(sizeof(struct TblNode));
    H->TableSize = 3*N;
    H->Cells = (Cell*)malloc(H->TableSize*sizeof(struct HashEntry));

    for(int i=0; i<H->TableSize; i++)
        H->Cells[i].InputTime = 0;
    return H;
}

int Hash(HashTable H, EleType key)
{
    return key%H->TableSize;
}

int LinearFind(HashTable H, EleType key)
{
    int CurPos, NewPos;
    CurPos = NewPos = Hash(H, key);

    int count = 0;
    while(H->Cells[NewPos].InputTime != 0 && H->Cells[NewPos].Data != key)
    {
        count++;
        NewPos = CurPos + count;
        if(NewPos>=H->TableSize)
            NewPos = NewPos%H->TableSize;
    }
    return NewPos;
}

void Insert(HashTable H, EleType key)
{
    int Pos = LinearFind(H, key);
    if(H->Cells[Pos].InputTime == 0)
    {
        H->Cells[Pos].Data = key;
        H->Cells[Pos].InputTime = 1;
    }
    else
    {
        H->Cells[Pos].InputTime++;
    }
}

int FindMaxInputTime(HashTable H)
{
    int i,Max;
    Max = 0;
    for(i=0; i<H->TableSize; i++)
    {
        if(H->Cells[i].InputTime>Max)
            Max = H->Cells[i].InputTime;
    }
    return Max;
}

void PrintResults(HashTable H)
{
    int MaxTimes = FindMaxInputTime(H);
    EleType MinNumber = MAXNUMBER;
    int count = 0;
    int i;
    for(i=0; i<H->TableSize; i++)
    {
        if(H->Cells[i].InputTime == MaxTimes)
        {
            count++;
            if(H->Cells[i].Data<MinNumber)
                MinNumber = H->Cells[i].Data;
        }
    }

    printf("%lld ", MinNumber);
    printf("%d", MaxTimes);
    if(count>1)
        printf(" %d", count);
}


int main()
{

    int N,i;
    EleType key;
    scanf("%d", &N);
    HashTable H = CreateTable(N);
    for(i=0; i<2*N; i++)
    {
        scanf("%lld", &key);
        Insert(H, key);
    }
    PrintResults(H);

    return 0;
}

