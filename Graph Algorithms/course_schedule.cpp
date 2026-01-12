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
bool isCycleExists;
void dfs(ll v, vector<vector<int>> &g, vector<int> &vis, vector<int> &pathVisited, vector<int> &sequence)
{
    if (isCycleExists)
        return;
    vis[v] = pathVisited[v] = true;
    for (ll child : g[v])
    {
        if (vis[child] && pathVisited[child])
        {
            isCycleExists = true;
            return;
        }
        else if (!vis[child])
            dfs(child, g, vis, pathVisited, sequence);
    }
    pathVisited[v] = false;
    sequence.push_back(v);
}
void solve()
{
    isCycleExists = false;
    int n, m, a, b;
    cin >> n >> m;
    vector<int> vis(n + 1, 0), pathVisited(n + 1, 0), sequence;
    vector<vector<int>> g(n + 1);
    while (m--)
    {
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (ll i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, g, vis, pathVisited, sequence);
    if (isCycleExists)
        cout << "IMPOSSIBLE";
    else
    {
        while (!sequence.empty())
        {
            cout << sequence.back() << ' ';
            sequence.pop_back();
        }
    }
    cout << nl;
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