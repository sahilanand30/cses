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
    if (n <= 3)
        cout << "NO SOLUTION\n";
    else
    {
        for (ll i = n; i >= 1; i -= 2)
            cout << i << " ";
        for (ll i = n - 1; i >= 1; i -= 2)
            cout << i << ' ';
        cout << nl;
    }
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