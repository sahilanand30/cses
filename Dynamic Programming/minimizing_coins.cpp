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
ll rec(ll x, vector<ll> &a, vector<ll> &dp)
{
    if (x == 0)
        return 0;
    if (dp[x] != -1)
        return dp[x];
    ll ans = INT_MAX;
    for (ll deno : a)
        if (deno <= x)
            ans = min(ans, 1 + rec(x - deno, a, dp));
    return dp[x] = ans;
}
void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), dp(x + 1, -1);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll ans = rec(x, a, dp);
    if (ans >= INT_MAX)
        ans = -1;
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