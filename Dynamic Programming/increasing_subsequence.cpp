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
    vector<ll> v;
    while (n--)
    {
        cin >> x;
        auto it = lower_bound(v.begin(), v.end(), x);
        if (it == v.end())
            v.push_back(x);
        else
            v[it - v.begin()] = x;
    }
    cout << v.size() << nl;
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