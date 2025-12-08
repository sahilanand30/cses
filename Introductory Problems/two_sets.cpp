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
    ll n;
    cin >> n;
    ll totalSum = (n * (n + 1)) / 2;
    if (totalSum % 2 == 0)
    {

        ll target = totalSum / 2;
        vector<ll> a, b;
        for (ll i = n; i >= 1; i--)
        {
            if (i <= target)
            {
                a.push_back(i);
                target -= i;
            }
            else
                b.push_back(i);
        }
        if (target == 0)
        {
            cout << "YES\n";
            cout << a.size() << nl;
            for (auto x : a)
                cout << x << ' ';
            cout << nl;
            cout << b.size() << nl;
            for (auto x : b)
                cout << x << ' ';
            cout << nl;
        }
        else
            cout << "NO\n";
    }
    else
        cout << "NO\n";
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