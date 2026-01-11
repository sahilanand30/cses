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

void solve()
{
    ll n, m, q, u, v, w, INF = 1e15;
    cin >> n >> m >> q;
    vector<vector<ll>> ans(n + 1, vector<ll>(n + 1, INF));
    for (ll i = 1; i <= n; i++)
        ans[i][i] = 0;
    while (m--)
    {
        cin >> u >> v >> w;
        ans[u][v] = ans[v][u] = min(ans[u][v], w);
    }
    for (ll k = 1; k <= n; k++)
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= n; j++)
                ans[i][j] = ans[j][i] = min(ans[i][j], ans[i][k] + ans[k][j]);
    while (q--)
    {
        cin >> u >> v;
        cout << ((ans[u][v] == INF) ? -1 : ans[u][v]) << nl;
    }
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