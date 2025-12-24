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
bool check(ll k, vector<ll> &v, ll x)
{
    ll total = 0;
    for (ll i : v)
    {
        total += (k / i);
        if (total >= x)
            return true;
    }
    return false;
}
void solve()
{
    ll n, x, lo = 1, hi = 0;
    cin >> n >> x;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        hi = max(hi, x * v[i]);
    }
    while (hi - lo > 1)
    {
        ll mid = (lo + hi) / 2;
        if (check(mid, v, x))
            hi = mid;
        else
            lo = mid;
    }
    if (check(lo, v, x))
        cout << lo << nl;
    else
        cout << hi << nl;
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