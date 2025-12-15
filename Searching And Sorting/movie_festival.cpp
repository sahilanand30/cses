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
ll rec(ll i, vector<pair<ll, ll>> &v, vector<ll> &dp)
{
    if (i >= v.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    ll ans = rec(i + 1, v, dp);
    pair<ll, ll> p = make_pair(v[i].second, -1);
    auto it = lower_bound(v.begin(), v.end(), p);
    ans = max(ans, 1 + rec(it - v.begin(), v, dp));
    return dp[i] = ans;
}
void solve()
{
    ll n, a, b;
    cin >> n;
    vector<ll> dp(n, -1);
    vector<pair<ll, ll>> v;
    while (n--)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    cout << rec(0, v, dp) << nl;
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