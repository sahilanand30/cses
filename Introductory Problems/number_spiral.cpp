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
    ll x, y, ans;
    cin >> x >> y;
    if (x < y)
    {
        if (y % 2 == 1)
        {
            ll r = y * y;
            cout << r - x + 1 << endl;
        }
        else
        {
            ll r = (y - 1) * (y - 1) + 1;
            cout << r + x - 1 << endl;
        }
    }
    else
    {
        if (x % 2 == 0)
        {
            ll r = x * x;
            cout << r - y + 1 << endl;
        }
        else
        {
            ll r = (x - 1) * (x - 1) + 1;
            cout << r + y - 1 << endl;
        }
    }
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