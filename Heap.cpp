#include <stdio.h>
#include <algorithm>
using namespace std;
int a[20000],n;

void up_heap(int n)
{
    while (n>1)
    {
        if (a[n]>a[n/2]){
            swap(a[n],a[n/2]);
            n=n/2;
        }
        else
            break;
    }
}

void push(int k)
{
    if (n<15000){
        n++;
        a[n]=k;
        up_heap(n);
    }
}

void down_heap()
{
    int i=1,c=1;
    while (c*2<=n)
    {
        c=c*2;
        if (c+1<=n && a[c]<a[c+1])
            c++;
        if (a[i]<a[c])
            swap(a[i],a[c]);
        else
            break;
        i=c;
    }
}

void pop()
{
    a[1]=a[n];
    n--;
    down_heap();

}

void input()
{
    char c;
    int k;
    //freopen("","r",stdin);
    while (scanf("%c",&c)!=EOF)
    {
        if (c=='+'){
            scanf("%i\n",&k);
            push(k);
        }
        else{
            int l=a[1];
            while (n>0 && a[1]==l){
                pop();
            }
            scanf("\n");
        }
    }
}

int main()
{
    input();
    int m=0,res[20000];
    while (n>0)
    {
        m++;
        res[m]=a[1];
        while(a[1]==res[m])
            pop();
    }
    printf("%i\n",m);
    for (int i=1;i<=m;i++)
        printf("%i\n",res[i]);
    return 0;
}
