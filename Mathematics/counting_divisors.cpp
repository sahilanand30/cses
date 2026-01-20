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
const ll N = 1000001;
vector<ll> ct(N, 0);
void solve()
{
    ll n, x;
    for (ll i = 1; i <= N; i++)
        for (ll j = i; j <= N; j += i)
            ct[j]++;
    cin >> n;
    while (n--)
    {
        cin >> x;
        cout << ct[x] << nl;
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