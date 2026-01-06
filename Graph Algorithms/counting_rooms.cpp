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
void dfs(ll i, ll j, vector<vector<char>> &v)
{
    ll n = v.size(), m = v[0].size();
    if (i >= n || j >= m || i < 0 || j < 0)
        return;
    if (v[i][j] == '#')
        return;
    v[i][j] = '#';
    vector<ll> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
    for (ll k = 0; k < 4; k++)
        dfs(i + dx[k], j + dy[k], v);
}
void solve()
{
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> v[i][j];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (v[i][j] == '.')
            {
                ans++;
                dfs(i, j, v);
            }
        }
    }
    cout << ans << nl;
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