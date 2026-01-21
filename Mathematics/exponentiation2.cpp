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
ll binpow(ll a, ll b, ll M)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}
void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    cout << binpow(a, binpow(b, c, mod - 1), mod) << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}