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

// dfs to find the 2 endpoints of the Diameter
void dfs(ll v, ll par, ll d, vector<vector<ll>> &g, vector<ll> &depth)
{
    depth[v] = d;
    for (ll child : g[v])
        if (child != par)
            dfs(child, v, d + 1, g, depth);
}

void calc(ll v, ll par, ll d, vector<vector<ll>> &g, vector<ll> &ans)
{
    ans[v] = max(ans[v], d);
    for (ll child : g[v])
        if (child != par)
            calc(child, v, d + 1, g, ans);
}
void solve()
{
    ll n, u, v, endpoint1, endpoint2, maxDepth = -1;
    cin >> n;
    vector<vector<ll>> g(n + 1);
    vector<ll> depth(n + 1, 0), ans(n + 1, 0);
    for (ll i = 1; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // finding endpoint1
    dfs(1, 1, 0, g, depth);
    for (ll i = 1; i <= n; i++)
    {
        if (depth[i] > maxDepth)
        {
            endpoint1 = i;
            maxDepth = depth[i];
        }
    }

    // finding endpoint2
    for (ll i = 0; i <= n; i++)
        depth[i] = 0;
    maxDepth = -1;
    dfs(endpoint1, endpoint1, 0, g, depth);
    for (ll i = 1; i <= n; i++)
    {
        if (depth[i] > maxDepth)
        {
            endpoint2 = i;
            maxDepth = depth[i];
        }
    }

    // Now from each endpoint find the distance from endpoint to that node
    calc(endpoint1, endpoint1, 0, g, ans);
    calc(endpoint2, endpoint2, 0, g, ans);
    for (ll i = 1; i <= n; i++)
        cout << ans[i] << ' ';
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