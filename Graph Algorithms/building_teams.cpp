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
bool ok;
void dfs(ll v, ll clr, map<ll, vector<ll>> &g, vector<ll> &color)
{
    if (color[v] != -1)
    {
        if (color[v] != clr)
            ok = false;
        return;
    }
    color[v] = clr;
    for (ll child : g[v])
        dfs(child, ((clr == 1) ? 2 : 1), g, color);
}
void solve()
{
    ok = true;
    ll n, m, u, v;
    cin >> n >> m;
    map<ll, vector<ll>> g;
    vector<ll> color(n + 1, -1);
    while (m--)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            dfs(i, 1, g, color);
            if (!ok)
            {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }
    for (ll i = 1; i <= n; i++)
        cout << color[i] << " ";
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