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
#define pll pair<int, int>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define derep(i,a,b) for(int i = (a); i>=(b); i--)
ll modi = 1000000007; 

void dijkastra(vector<vector<pair<int, int> > > weightedGraph, bool visited[], int n ){
    int startingNode, temp = n;
    cin>>startingNode;
    int costs[n+1];
    memset(costs, modi, sizeof(costs));
    costs[startingNode] = 0;
    while(n--){
        visited[startingNode] = true;
        cout<<"starting Node is "<<startingNode<<"and it's cost is "<<costs[startingNode]<<endl;
        for(auto itr : weightedGraph[startingNode]){
            pll p = itr;
            int target = p.first;
            int weight = p.second;
            cout<<"the target and the weight is "<<target<<" "<<weight<<endl;
            if(!visited[target] && costs[startingNode] + weight < costs[target]){
                cout<<"prev = "<<costs[target]<<endl;
                costs[target] = costs[startingNode] + weight;  
                cout<<"now = "<<costs[target]<<endl;
            }
        }
        int weight, target;
        weight  = modi;
        rep(i, 1, temp+1){
            if(!visited[i] && costs[i] < weight){
                weight = costs[i];
                target = i;
            }
        }
        startingNode = target;
    }
    rep(i, 1, temp + 1){
        cout<<"to reach to node "<<i<<" cost is "<<costs[i]<<endl;
    }
}
void graphInput(){
    int n;
    cin>>n;
    int roads;
    cin>>roads;
    vector< vector<pair<int , int> > > weightedGraph(n + 1);
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));
    rep(i, 0, roads){
        int vertex1 , vertex2;
        // cin>>vertex1>>vertex2;
        // graph[vertex1].pb(vertex2);
        // graph[vertex2].pb(vertex1); // comment this line for directed graph.

        //for weightedGraph

       int weight;
       cin>>vertex1>>vertex2>>weight;
       weightedGraph[vertex1].pb(make_pair(vertex2, weight));
       weightedGraph[vertex2].pb(make_pair(vertex1, weight)); // comment this line for directed graph
    }
    dijkastra(weightedGraph, visited, n);
}


int32_t main(){
    cout<<INFINITY<<endl;
    graphInput();
}
