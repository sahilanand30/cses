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
void dfs(ll v, ll p, vector<vector<ll>> &g, ll d, vector<ll> &depth)
{
    depth[v] = d++;
    for (ll child : g[v])
        if (child != p)
            dfs(child, v, g, d, depth);
}
void solve()
{
    ll n, u, v, root, maxDepth = -1;
    cin >> n;
    vector<vector<ll>> g(n + 1);
    vector<ll> depth(n + 1, 0);
    for (ll i = 1; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1, g, 0, depth);
    for (ll i = 1; i <= n; i++)
    {
        if (depth[i] > maxDepth)
        {
            maxDepth = depth[i];
            root = i;
        }
    }
    for (ll i = 0; i <= n; i++)
        depth[i] = 0;
    dfs(root, root, g, 0, depth);
    cout << (*max_element(depth.begin(), depth.end())) << nl;
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