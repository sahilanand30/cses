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
        return 0;
    if (dp[n] != -1)
        return dp[n];
    ll ans = INT_MAX, x = n;
    while (x > 0)
    {
        if (x % 10)
            ans = min(ans, 1 + rec(n - (x % 10),dp));
        x /= 10;
    }
    return dp[n] = ans;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll>dp(n+1);
    cout<<rec(n,dp)<<nl;
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