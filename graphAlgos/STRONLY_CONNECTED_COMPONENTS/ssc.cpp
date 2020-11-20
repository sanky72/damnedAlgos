#include <bits/stdc++.h>
//#include <boost/algorithm/string.hpp>
using namespace std;
typedef long long int ll;
#define int ll
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rev(a) (a).rbegin(), (a).rend()
#define pll pair<ll, ll>
#define rep(i, a, b) for (long long i = (a); i < (b); i++)
#define derep(i, a, b) for (long long i = (a); i >= (b); i--)
ll modi = 1000000007;
stack<int> stackForScc;

void dfs1(vector<vector<int>> graph, bool visited[], int node)
{
    visited[node] = true;
    for (auto it : graph[node])
    {
        if (!visited[it])
        {
            dfs1(graph, visited, it);
        }
    }
    stackForScc.push(node);
}

void dfs2(vector<vector<int>> graph, bool visited[], int node)
{
    visited[node] = true;
    cout << node << " ";
    for (auto it : graph[node])
    {
        if (!visited[it])
        {
            dfs2(graph, visited, it);
        }
    }
}

vector<vector<int>> doTranspose(vector<vector<int>> graph)
{
    vector<vector<int>> transposedGraph(graph.size());
    rep(i, 1, graph.size())
    {
        for (auto it : graph[i])
        {
            transposedGraph[it].pb(i);
        }
    }
    return transposedGraph;
}
void graphInput()
{
    int n;
    cin >> n;
    int roads;
    cin >> roads;
    vector<vector<int>> graph(n + 1);
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));
    rep(i, 0, roads)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        graph[vertex1].pb(vertex2);
    }
    rep(i, 1, n + 1)
    {
        if (!visited[i])
        {
            dfs1(graph, visited, i);
        }
    }

    vector<vector<int>> transposedGraph = doTranspose(graph);

    memset(visited, false, sizeof(visited));

    while (!stackForScc.empty())
    {
        int node = stackForScc.top();
        stackForScc.pop();
        if (!visited[node])
        {
            dfs2(transposedGraph, visited, node);
            cout << endl;
        }
    }
}

int32_t main()
{
    graphInput();
}
