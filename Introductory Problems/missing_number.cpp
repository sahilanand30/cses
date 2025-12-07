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
    ll n, x;
    cin >> n;
    vector<bool> a(n + 1, false);
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> x;
        a[x] = true;
    }
    for (ll i = 1; i < n + 1; i++)
        if (!a[i])
            cout << i << nl;
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