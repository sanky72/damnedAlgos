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

bool cp(ll n){
    if(n == 1)return false;
    else if(n == 2)return true;
    else if(n ==3)return true;
    for(int i  = 2; i*i<=n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
void SforPrime(int n)
{
	bool prime[n+1];
	memset(prime, true, sizeof(prime));

	for (int p=2; p*p<=n; p++)
	{
		if (prime[p] == true)
		{
			for (int i=p*p; i<=n; i += p)
				prime[i] = false;
		}
	}
}
ll calPower(ll val, ll n){
    ll i = 1;
    ll ind = 1;
    ll prev = val;
    while(val<=n){
        if(n%val == 0)ind = i;
        val  = val*prev;
        i++;
    }
    return i-1;
}

void actualDfs(vector<vector<int> > graph, bool visited[], int curr, int parent){
    visited[curr] = true;
    cout<<"the current node is "<<curr<<endl;
    rep(i, 0, graph[curr].size()){
        if(graph[curr][i] != parent && !visited[graph[curr][i]])
            actualDfs(graph, visited, graph[curr][i], curr);
    }
}

void actualBfs(vector<vector<int> > graph, bool visited[], queue<int> dfsQ){

    while(!dfsQ.empty())
    {
        int curr=dfsQ.front();
        cout<<"the current node is "<<curr<<endl;
        dfsQ.pop();
        rep(i, 0, graph[curr].size()){
            if(!visited[graph[curr][i]]){
                visited[curr] = true;
                dfsQ.push(graph[curr][i]);
            }
        }
    }
}
void dfsInput(){
    int n;
    cin>>n;
    int roads;
    cin>>roads;
    cout<<"here"<<endl;
    vector< vector<int>> graph(n + 1);
    //vector< vector<pair<int, int>> > weightedGraph(n);
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
    cout<<"im here "<<endl;
    actualDfs(graph, visited, 1, -1); // this execution is for printing the edges only.
    cout<<"calling dfs "<<endl;
    queue<int> bfsQ;
    bfsQ.push(1);
    bool bfsVisited[n+1];
    memset(bfsVisited, false, sizeof(bfsVisited));
    actualBfs(graph, bfsVisited, bfsQ);

}
int32_t main(){
    //Me && It
    //fast;
    ll t;
    cin>>t;
    while(t--){
        dfsInput();
    }
}
