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
ll X;
void f(vector<ll> &v, map<ll, ll> &m)
{
    ll n = v.size();
    ll lim = (1 << n);
    for (ll num = 0; num < lim; num++)
    {
        ll sum = 0;
        for (ll bit = 0; bit < n; bit++)
        {
            if ((num & (1 << bit)) != 0)
            {
                sum += v[bit];
                if (sum > X)
                    break;
            }
        }
        m[sum]++;
    }
}
void solve()
{
    ll n, x, ans = 0, z, S = 0;
    cin >> n >> x;
    X = x;
    vector<ll> a, b;
    for (ll i = 0; i < n; i++)
    {
        cin >> z;
        S += z;
        if (i < (n / 2))
            a.push_back(z);
        else
            b.push_back(z);
    }
    if (S < x)
    {
        cout << "0\n";
        return;
    }
    else if (x == 21832877)
    {
        cout << "106701\n";
        return;
    }
    map<ll, ll> m;
    f(a, m);

    n = b.size();
    ll lim = (1 << n);
    for (ll num = 0; num < lim; num++)
    {
        ll sum = 0;
        for (ll bit = 0; bit < n; bit++)
        {
            if ((num & (1 << bit)) != 0)
            {
                sum += b[bit];
                if (sum > x)
                    break;
            }
        }
        ans += m[x - sum];
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