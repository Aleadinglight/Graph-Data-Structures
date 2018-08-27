#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    int n,m;
    // Input n - number of vertices,and m - number of edges
    cin>>n>>m;
    vector<vii> adjList(n+1); //For vertex 1..n
    // m next lines each contains 3 int "u v c" meaning: edges from u->v with cost c
    int u,v,c;
    // Read file
    for (int i=0; i<m; i++){
        cin>>u>>v>>c;
        // Each element in adjList[u] is a vertex v that is connected to u with cost C 
        adjList[u].push_back(make_pair(v, c));
    }
    // Print out the edges stored in Adjacency List
    for (int i=0; i<n; i++){
        for (int j=0; j<adjList[i].size(); j++)
            cout<<i<<"->"<<adjList[i][j].first<<" costs "<<adjList[i][j].second<<endl;
    }
    return 0;
}
