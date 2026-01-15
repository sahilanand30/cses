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
ll dfs(ll v, vector<vector<ll>> &g, vector<ll> &vis, vector<ll> &sum)
{
    ll ans = 0;
    vis[v] = 1;
    for (ll child : g[v])
    {
        if (vis[child] == 0)
        {
            ans += dfs(child, g, vis, sum);
        }
    }
    sum[v] = ans;
    return ans + 1;
}
void solve()
{
    ll n, v;
    cin >> n;
    vector<ll> vis(n + 1, 0), sum(n + 1, 0);
    vector<vector<ll>> g(n + 1);
    for (ll i = 2; i <= n; i++)
    {
        cin >> v;
        g[v].push_back(i);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, g, vis, sum);
        }
    }
    for (ll i = 1; i <= n; i++)
        cout << sum[i] << " ";
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