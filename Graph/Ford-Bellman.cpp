#include <stdio.h>
#include <stdlib.h>

int maxx=0,a[101][101],L[101],t[101],n,k,l;

void input(){
    int i,j;
    freopen("input.inp","r",stdin);
    // Find the shortest path from vertex k -> vertex l
    scanf("%i %i %i",&n,&k,&l);
    for (i=1;i<=n;i++)
        for ( j=1;j<=n;j++){
            scanf("%i",&a[i][j]);
            maxx+=a[i][j];
        }
}

void init()
{
    int i,j;
    // if there is no direct way from i->j, a[i][j]=maxx+1 so we gonna ignore it later
    // (since if we put it =0 it gonna effect the shorted path)
    for ( i=1;i<=n;i++)
        for (j=1;j<=n;j++){
            if (i!=j && a[i][j]==0)
                a[i][j]=maxx+1;
        }
    // Let L[i] is the shortest path between k -> i
    for ( i=1;i<=n;i++){
        L[i]=a[k][i];
    /*t[i] is the previous vertex of i in the shortest path from k->i
        we initiate all t[i] is from k
        we dont need to check if there is a path from k -> i
        since we already set L[i]=maxx+1 so we guarantee that we wont choose them anyway */
        t[i]=k;
    }

}

void xuli()
{
    init();
    int kt=1,u,v;
    // We stop when we cant no longer optimize L[i]
    while (kt)
    {
        kt=0;
        // if after this kt still =0 meaning that there is no way to minimize L[i] anyway, so we stop
        for (u =1;u<=n;u++)
            for (v=1;v<=n;v++)
                if (L[v]>L[u]+a[u][v])
                {
                    // minimize L[v]
                    L[v]=L[u]+a[u][v];
                    // record the vertex to traceback.
                    t[v]=u;
                    // this mean we still have vertex to minimize to we put k=1
                    kt=1;
                }
    }
}

void output()
{
    int res[101],d=0,i;
    if (k==l)
    {
        printf("The shortest path costs: 0\n");
        printf("%i -> %i",k,l);
        return;
    }
    if (L[l]==maxx+1){
    //this mean that there is no way to go from k -> l
        printf("Vertex %i cannot be reached from %i",l,k);
    }
    else{
        // This mean we have a result so we gonna display it
        res[1]=l;
        d++;
        i=l;
        // We trace back from l until we find out k
        while (i!=k){
            d++;
            res[d]=t[i];
            i=t[i];
        }
        // Now we print the result
        printf("The shortest path costs: %i\n",L[l]);
        for (i=d;i>1;i--)
            printf("%i -> ",res[i]);
        printf("%i\n",res[1]);
    }
}

int main(void)
{
    input();
    xuli();
    output();
    return 0;
}
