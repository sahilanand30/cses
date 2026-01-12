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
    ll n, m, INF = 1e18;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> g(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
    dist[1][0] = 0;

    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq;
    pq.push({0, 1, 0}); // cost, node, usedDiscount

    while (!pq.empty())
    {
        auto [d, u, used] = pq.top();
        pq.pop();
        if (d > dist[u][used])
            continue;

        for (auto [v, w] : g[u])
        {
            // without discount
            if (d + w < dist[v][used])
            {
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }
            // use discount if not used yet
            if (!used && d + w / 2 < dist[v][1])
            {
                dist[v][1] = d + w / 2;
                pq.push({dist[v][1], v, 1});
            }
        }
    }

    cout << dist[n][1] << "\n";
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