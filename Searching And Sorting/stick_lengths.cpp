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
    ll n, tot = 0, curr = 0, ans = 1e16;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        tot += a[i];
    }
    sort(a, a + n);
    for (ll i = 0; i < n; i++)
    {
        tot -= a[i];
        ans = min(ans, abs((a[i] * i) - curr) + abs((a[i] * (n - i - 1)) - tot));
        curr += a[i];
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