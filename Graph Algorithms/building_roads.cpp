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
void dfs(ll v, map<ll, vector<ll>> &g, vector<bool> &vis)
{
    vis[v] = true;
    for (ll child : g[v])
        if (!vis[child])
            dfs(child, g, vis);
}
void solve()
{
    vector<ll> parents;
    ll n, m, u, v;
    cin >> n >> m;
    vector<bool> vis(n + 1, false);
    map<ll, vector<ll>> g;
    while (m--)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            parents.push_back(i);
            dfs(i, g, vis);
        }
    }
    ll len = parents.size();
    cout << len - 1 << nl;
    for (ll i = 1; i < len; i++)
        cout << parents[i] << " " << parents[i - 1] << nl;
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