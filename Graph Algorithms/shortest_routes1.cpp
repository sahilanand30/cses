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
    vector<vector<pair<ll, ll>>> g(n + 1);
    while (m--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    vector<ll> dis(n + 1, 1e15);
    dis[1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if (currentDistance > dis[currentNode])
            continue;

        for (auto [child, weight] : g[currentNode])
        {
            ll newDist = currentDistance + weight;
            if (newDist < dis[child])
            {
                dis[child] = newDist;
                pq.push({newDist, child});
            }
        }
    }

    for (ll i = 1; i <= n; i++)
        cout << dis[i] << " ";
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