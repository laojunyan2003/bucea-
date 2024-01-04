#include<stdio.h>
#include<string.h>
int visit[100]={0};
int G[100][100];
void DFS(int i,int n);
void BFS(int i,int n);

int main(void) {
    int n,i,m,a,b;
    scanf ("%d %d",&n,&m);
    for (i=0;i<m;i++) {
        scanf ("%d %d",&a,&b);
        G[a][b]=G[b][a]=1;
    }
    for (i=0;i<n;i++) {
        if (visit[i]==0) {
            printf ("{");
            DFS(i,n);
            printf (" }\n");
        }
    }
    for (i=0;i<n;i++) {
        visit[i]=0;
    }
    //visit[100]={0};
    for (i=0;i<n;i++) {
        if (visit[i]==0) {
            printf ("{");
            BFS(i,n);
            printf (" }\n");
        }
    }
    return 0;
}
void DFS(int i,int n) {
    int j;
    printf (" %d",i);
    visit[i]=1;
    for (j=0;j<n;j++) {
        if(visit[j]==0&&G[i][j]==1) {
            DFS(j,n);
        }
    }
}
void BFS(int i,int n) {
    int a[100],j,x=-1,y=-1,last=0,v;
    visit[i]=1;
    a[++x]=i;
    while(1) {
        if (x==y) break;
        v=a[++y];
        printf (" %d",v);
        for (j=0;j<n;j++) {
            if (visit[j]==0&&G[v][j]==1) {
                a[++x]=j;
                visit[j]=1;
            }
        }
    }
}
