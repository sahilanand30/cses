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
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> g(n + 1);
    vector<ll> indeg(n + 1, 0), topo;

    while(m--)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }

    queue<ll> q;
    for (ll i = 1; i <= n; i++)
        if (indeg[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        topo.push_back(u);
        for (ll v : g[u])
        {
            if (--indeg[v] == 0)
                q.push(v);
        }
    }

    vector<ll> dp(n + 1, 0);
    dp[1] = 1;

    for (ll u : topo)
        for (ll v : g[u])
            dp[v] = (dp[v] + dp[u]) % mod;

    cout << dp[n] << "\n";
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