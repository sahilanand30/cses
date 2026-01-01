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
ll binpow(ll base, ll pow)
{
    ll ans = 1;
    while (pow)
    {
        if (pow & 1)
            ans = (ans * base) % mod;
        base = (base * base) % mod;
        pow >>= 1;
    }
    return ans;
}
ll rec(ll n, ll tar, vector<vector<ll>> &dp)
{
    if (tar == 0)
        return 1;
    if (n == 0)
        return 0;
    if (dp[n][tar] != -1)
        return dp[n][tar];

    ll op1 = 0, op2 = rec(n - 1, tar, dp);
    if (n <= tar)
        op1 = rec(n - 1, tar - n, dp);
    return dp[n][tar] = (op1 + op2) % mod;
}
void solve()
{
    ll n;
    cin >> n;
    ll total = (n * (n + 1)) / 2;
    vector<vector<ll>> dp(n+1, vector<ll>((total / 2) + 1, -1));
    if (total % 2 == 0)
        cout << (rec(n, total / 2, dp) * binpow(2, mod - 2)) % mod << nl;
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