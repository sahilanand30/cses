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
    ll n, m, u, v;
    cin >> n >> m;
    vector<ll> par(n + 1, -1), ans;
    par[1] = 1;
    map<ll, vector<ll>> g;
    while (m--)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<ll> q;
    q.push(1);
    while (!q.empty())
    {
        ll f = q.front();
        q.pop();
        for (ll x : g[f])
        {
            if (par[x] == -1)
            {
                q.push(x);
                par[x] = f;
            }
        }
    }
    while (n != -1)
    {
        ans.push_back(n);
        n = par[n];
        if (n == 1)
        {
            ans.push_back(n);
            break;
        }
    }
    if (n == -1)
        cout << "IMPOSSIBLE\n";
    else
    {
        reverse(ans.begin(), ans.end());
        cout << ans.size() << nl;
        for (ll x : ans)
            cout << x << " ";
        cout << nl;
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