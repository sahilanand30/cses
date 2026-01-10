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
bool found;

void dfs(ll v, vector<vector<ll>> &g, vector<ll> &path, vector<ll> &vis, ll par)
{
    if (found)
        return;

    path.push_back(v);
    vis[v] = 1; // in recursion stack

    for (ll child : g[v])
    {
        if (child == par)
            continue;

        if (vis[child] == 1 && !found)
        {
            // Found cycle — extract only the cycle part
            vector<ll> cycle;
            cycle.push_back(child);

            for (int i = path.size() - 1; i >= 0; i--)
            {
                cycle.push_back(path[i]);
                if (path[i] == child)
                    break;
            }

            reverse(cycle.begin(), cycle.end());

            cout << cycle.size() << nl;
            for (ll x : cycle)
                cout << x << " ";
            cout << nl;

            found = true;
            return;
        }

        if (vis[child] == 0)
            dfs(child, g, path, vis, v);

        if (found)
            return;
    }

    path.pop_back();
    vis[v] = 2; // finished
}
void solve()
{
    found = false;
    ll n, m, u, v;
    cin >> n >> m;
    vector<vector<ll>> g(n + 1);
    while (m--)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> path, vis(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs(i, g, path, vis, -1);
        if (found)
            return;
    }
    cout << "IMPOSSIBLE\n";
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