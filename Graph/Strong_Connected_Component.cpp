#include <stdio.h>
#include <stack>

using namespace std;
stack <int> store;
int m,n,a[10000][10000],number[10000], low[10000],check[10000],d=0,component=0;

// Input:  m - number of edge, n - vertex.
void input()
{
    int x,y;
    freopen("input.inp","r",stdin);
    scanf("%i %i",&m,&n);
    for(int i=0;i<m;i++){
        scanf("%i %i",&x,&y);
        // Adjacency Matrix
        a[x-1][y-1]=1;
    }
}

void Visit(int u)
{
    d++;
    number[u]=d;
    low[u]=number[u];
    store.push(u);
    for (int i=0;i<n;i++)
        if (check[i]==0 && a[u][i]==1)
            if (number[i]!=0)
                low[u]=min(low[u],number[i]);
            else{
                Visit(i);
                low[u]=min(low[u],low[i]);
            }
    if (low[u]==number[u])
    {
        component++;
        printf("Connected component number: %i\n",component);
        while(store.top()!=u)
        {
            printf("%i --> ",store.top()+1);
            check[store.top()]=1;
            store.pop();
        }
        printf("%i",store.top()+1);
        check[store.top()]=1;
        store.pop();
        printf("\n");
    }
}

void Start()
{
    for (int i=0;i<n;i++)
        if (check[i]==0)
            Visit(i);
}

void init()
{
    for (int i=0;i<n;i++)
        a[i][i]=1;
}

int main()
{
    input();
    init();
    Start();
    return 0;
}
