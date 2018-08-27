#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    int n,m;
    // Input n - number of vertices,and m - number of edges
    cin>>n>>m;
    priority_queue< pair<int, ii> > EdgeList;  //For edges 1..m
    // m next lines each contains 3 int "u v c" meaning: edges from u->v with cost c
    // Here we implement a priority queue to sort the cost of the edges
    // There for the EdgeList.first is the cost, EdgeList.second is a pair of two vertices
    int u,v,c;
    for (int i=0; i<m; i++){
        cin>>u>>v>>c;

        EdgeList.push(make_pair(c, make_pair(u, v)));
    }
    // Print out the edges stored in Adjacency List

    while (EdgeList.size()>0){
        cout<<EdgeList.top().second.first<<"->"<<EdgeList.top().second.second<<" costs "<<EdgeList.top().first<<endl;
        EdgeList.pop();
    }
    return 0;
}
