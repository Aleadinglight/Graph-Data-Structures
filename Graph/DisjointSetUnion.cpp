#include <stdio.h>

using namespace std;
struct canh{
    int x,y;
};
int n,m,r[100010];
canh a[100010];

/**
    In this example we will input in edges of a tree,
    then we will build a tree based on this input using disjoint union set technique:
    Finding the parent of a node, then decide where that node locates in this tree.
**/
void input(){
    // Input: m - number of edge, n - vertex.
    freopen("input.inp","r",stdin);
    scanf("%i %i",&n,&m);
    for (int i=1;i<=m;i++)
        scanf("%i %i",&a[i].x,&a[i].y);
}

// Return the root of the set containing this child
int root(int k){
    while (r[k]>0){
        k=r[k];
    }
    return k;
}

void createTree()
{
    int r1,r2;
    // For each edge, we look at the two vertex
    for (int i=1;i<=m;i++)
    {
        // Finding the parent of each vertex
        r1 = root(a[i].x);
        r2 = root(a[i].y);

        // If they are not from the same set
        if (r1!=r2)
            // This mean that r1 has more children than r2
            // smaller negative number means more children
            if (r[r1]<r[r2]){
                // In this case, we must set r2 to be child of r1
                // increase r1 number of children
                r[r1]=r[r1]+r[r2];
                // Declare r1 as the root of r2
                r[r2]=r1;
                // Declare r1 is the root of a[i].y in case we go through it next time
                // for better performance.
                r[a[i].y]=r1;
            }
            // The same, in revert situation
            else{
                r[r2]=r[r1]+r[r2];
                r[r1]=r2;
                r[a[i].x]=r2;
            }
    }
}

// Print the root of
void output()
{
    freopen("output.out","w",stdout);
    for (int i=1;i<=n;i++)
        printf("%i --> %i\n",i,root(i));
}

void init()
{
/**
    All the node is initiated to be a root
    The root node contain a negative number determine the number of child it has.
    The positive value in a node determine its parent, and it is not a root.
**/
    for (int i=1;i<=n;i++)
        r[i]=-1;
}

int main(){
    // Read the data
    input();
    // Initiate the parents of all sets to -1
    init();
    // Create a tree base on the input
    createTree();
    output();
    return 0;
}
