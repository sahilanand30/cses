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

ll rec(ll n, vector<ll> &dp)
{
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    ll ans = 0;
    for (ll i = 1; i <= 6; i++)
        if (i <= n)
            ans = (ans + rec(n - i, dp)) % mod;
    return dp[n] = ans;
}
ll iterative(ll n)
{
    vector<ll>dp(n+1,0);
    dp[0] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll k = 1; k <= 6; k++)
            if (k <= i)
                dp[i] = (dp[i] + dp[i - k]) % mod;
    return dp[n];
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> dp(n + 1, -1);
    // cout << rec(n, dp) << nl;
    cout << iterative(n) << nl;
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