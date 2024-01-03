#include <stdio.h>
#define MaxTree 10
#define Null -1

typedef int Tree ;
typedef char  ElementType ;

struct TreeNode
{
    ElementType Element ;
    Tree Left ;
    Tree Right ;
} Tree1[MaxTree],Tree2[MaxTree];

Tree BuildeTree(struct TreeNode T[])
{
    int i,N,check[MaxTree];
    char cl,cr;
    int Root;
    scanf("%d",&N);

    if(N!=0)
    {
        for( i=0;i<N;i++) check[i] = 0 ;
        for( i=0;i<N;i++)
        {
            scanf(" %c %c %c",&T[i].Element,&cl,&cr) ;

            if(cl!='-')
            {
                T[i].Left=cl-'0' ;
                check[T[i].Left]=1 ;
            }
            else T[i].Left=Null ;

            if(cr!='-')
            {
                T[i].Right =cr-'0' ;
                check[T[i].Right]=1 ;
            }
            else T[i].Right=Null ;
        }
    }
    else
        return  Null ;

    for(i=0;i<N;i++ )
    {
        if(check[i]==0 )
            break ;
    }
    Root=i ;

    return  Root ;
}
int Isomorphic(Tree R1,Tree R2)
{
    if((R1==Null)&&(R2==Null))
        return 1;
    if(((R1==Null)&&(R2!=Null))||((R2==Null)&&(R1!=Null)))
        return 0;
    if(Tree1[R1].Element!=Tree2[R2].Element)
        return 0;
    else
    {
        if(Isomorphic(Tree1[R1].Left,Tree2[R2].Left)&&Isomorphic(Tree1[R1].Right,Tree2[R2].Right))
            return 1;
        else if(Isomorphic(Tree1[R1].Left,Tree2[R2].Right)&&Isomorphic(Tree1[R1].Right,Tree2[R2].Left))
            return 1;
        else
            return 0;
    }
}

int main(  )
{
    Tree Root1 , Root2 ;
    Root1 = BuildeTree( Tree1 ) ;
    Root2 = BuildeTree( Tree2 ) ;


    if( Isomorphic( Root1,Root2 ) )
        printf("Yes\n") ;
    else
        printf("No\n") ;

    return 0 ;

}
