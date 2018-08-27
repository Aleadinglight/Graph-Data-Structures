#include <stdio.h>
#include <stack>
using namespace std;

int n,m,k,a[10001][10001],check[10001],x[10001];

// Hamilton Cycle: n - number of vertex, m - number of edge, k - the start of Hamilton cycle.
// Each of the next m lines contain an edge meaning there is a connection from x -> y.
void input()
{
    int x,y;
    freopen("input.inp","r",stdin);
    scanf("%i %i %i",&n,&m,&k);
    for (int i=1;i<=m;i++)
    {
        scanf("%i %i",&x,&y);
        a[x][y]=1;
        a[y][x]=1;
    }
}

void output()
{
    for (int i=1;i<=n;i++)
        printf("%i ",x[i]);
    printf("%i ",k);
    printf("\n");
}

void Try(int i)
{
    if (i<=n){
        for (int j=1;j<=n;j++)
            if (check[j]==0 && a[x[i-1]][j]==1)
            {
                check[j]=1;
                x[i]=j;
                Try(i+1);
                check[j]=0;
            }
    }
    else
        if (a[x[i-1]][k]==1)
            output();
}

int main()
{
    input();
    check[k]=1;
    x[1]=k;
    Try(2);
    return 0;
}
