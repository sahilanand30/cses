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
ll rec(ll i, ll j, vector<vector<char>> &v, vector<vector<ll>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll ans = 0;
    if (i - 1 >= 0 && v[i - 1][j] == '.')
        ans = (ans + rec(i - 1, j, v, dp)) % mod;
    if (j - 1 >= 0 && v[i][j - 1] == '.')
        ans = (ans + rec(i, j - 1, v, dp)) % mod;
    return dp[i][j] = ans;
}
void solve()
{
    ll n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> v[i][j];
    if (v[n - 1][n - 1] == '.')
        cout << rec(n - 1, n - 1, v, dp) << nl;
    else
        cout << "0\n";
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