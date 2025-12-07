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
    while (true)
    {
        cout << n << ' ';
        if (n == 1)
            break;
        if (n % 2 == 0)
            n /= 2;
        else
            n = (n * 3) + 1;
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