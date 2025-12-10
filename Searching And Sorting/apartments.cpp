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

void solve()
{
    ll n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while (!a.empty() && !b.empty())
    {
        ll x = a.back(), y = b.back();
        if (y >= x - k && y <= x + k)
        {
            ans++;
            a.pop_back();
            b.pop_back();
        }
        else if (x < y)
            b.pop_back();
        else
            a.pop_back();
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