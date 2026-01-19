/*
Author: Sahil Anand
Find me on: https://linktr.ee/sahilanand30
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define nl endl
/*-------------------------{Main Code}-------------------------*/
vector<int> adj[200005];
bool matched[200005];
int answer;

void dfs(int u, int parent)
{
    // First, visit all children
    for (int v : adj[u])
    {
        if (v == parent)
            continue;
        dfs(v, u);
    }

    // Now we're back at node u after processing all children
    // If u is not matched AND parent is not matched
    // Then match u with parent!
    if (!matched[u] && parent != -1 && !matched[parent])
    {
        matched[u] = true;
        matched[parent] = true;
        answer++;
    }
}

void solve()
{
    answer=0;
    int n,u,v;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cout << answer << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}