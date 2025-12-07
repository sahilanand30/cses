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
    string s;
    cin >> s;
    ll n = s.size(), ct = 1, ans = 0;
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            ct++;
        else
            ct = 1;
        ans = max(ans, ct);
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