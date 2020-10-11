#include<bits/stdc++.h>
//#include <boost/algorithm/string.hpp> 
using namespace std;
typedef long long int ll;
#define int ll
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define rev(a) (a).rbegin(),(a).rend()
#define pll pair<ll,ll>
#define rep(i,a,b) for(long long i = (a); i < (b); i++)
#define derep(i,a,b) for(long long i = (a); i>=(b); i--)
ll modi = 1000000007;
void graphInput(){
    int n;
    cin>>n;
    int roads;
    cin>>roads;
    vector< vector<int>> graph(n + 1);
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));
    rep(i, 0, roads){
        int vertex1 , vertex2;
        cin>>vertex1>>vertex2;
        graph[vertex1].pb(vertex2);
        graph[vertex2].pb(vertex1); // comment this line for directed graph.

        //for weightedGraph

//        int weight;
//        cin>>vertex1>>vertex2>>weight;
        //weightedGraph[vertex1].pb(make_pair(vertex2, weight));
        //weightedGraph[vertex2].pb(make_pair(vertex1, weight)); // comment this line for directed graph
    }
}

int32_t main(){
    graphInput();
}