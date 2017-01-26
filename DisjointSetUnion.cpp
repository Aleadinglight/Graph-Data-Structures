#include <stdio.h>

using namespace std;
struct canh{
    int x,y;
};
int n,m,r[100010];
canh a[100010];

void input()
{
    freopen("input.inp","r",stdin);
    scanf("%i %i",&n,&m);
    for (int i=1;i<=m;i++)
        scanf("%i %i",&a[i].x,&a[i].y);
}

int root(int k)
{
    while (r[k]>0)
    {
        k=r[k];
    }
    return k;
}

void xuli()
{
    int r1,r2;
    for (int i=1;i<=m;i++)
    {
        r1 = root(a[i].x);
        r2 = root(a[i].y);
        if (r1!=r2)
            if (r[r1]<r[r2]){
                r[r1]=r[r1]+r[r2];
                r[r2]=r1;
                r[a[i].y]=r1;
            }
            else{
                r[r2]=r[r1]+r[r2];
                r[r1]=r2;
                r[a[i].x]=r2;
            }
    }
}

void output()
{
    freopen("output.out","w",stdout);
    for (int i=1;i<=n;i++)
        printf("%i --> %i\n",i,root(i));
}

void init()
{
    for (int i=1;i<=n;i++)
        r[i]=-1;
}

int main()
{
    input();
    init();
    xuli();
    output();
    return 0;
}
