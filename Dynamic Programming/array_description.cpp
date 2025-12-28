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
ll dp[100001][101];
ll rec(ll i, ll last, ll m, vector<ll> &a)
{
    if (i < 0)
        return 1;
    if(dp[i][last]!=-1)return dp[i][last];

    ll ans = 0;
    if (a[i] == 0)
    {
        ans = (ans + rec(i - 1, last, m, a)) % mod;
        if (last - 1 >= 1)
            ans = (ans + rec(i - 1, last - 1, m, a)) % mod;
        if (last + 1 <= m)
            ans = (ans + rec(i - 1, last + 1, m, a)) % mod;
    }
    else if (abs(last - a[i]) <= 1)
        ans = rec(i - 1, a[i], m, a);
    return dp[i][last] = ans;
}
void solve()
{
    memset(dp,-1,sizeof(dp));
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    if (a.back() == 0)
        for (ll i = 1; i <= m; i++)
            ans = (ans + rec(n - 2, i, m, a)) % mod;
    else
        ans = rec(n - 1, a[n - 1], m, a);
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