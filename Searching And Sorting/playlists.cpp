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
    ll n, i = 0, j = 0, ans = 0;
    cin >> n;
    ll a[n];
    for (ll k = 0; k < n; k++)
        cin >> a[k];
    map<ll, ll> m;
    while (i < n)
    {
        while (j < n && m[a[j]] == 0)
        {
            m[a[j]]++;
            ans = max(ans, j - i + 1);
            j++;
        }
        m[a[i]]--;
        i++;
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