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
/*
LOGIC:
- This problem can be solved by stars and bars method
- So we can think like this, apples like stars and we will put bars in between
- n=child, m=apples
- total_positions = m+(n-1) => as we need (n-1) bars to make n groups of apples
- so in this total_positions you can choose 'm' stars or 'n-1' bars
*/
const ll N = 2000005;
vector<ll> fact(N), inverse(N);
ll binpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return ans;
}
void solve()
{
    fact[0] = inverse[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        inverse[i] = binpow(fact[i], mod - 2);
    }

    ll bars, stars;
    cin >> bars >> stars;
    ll total_positions = stars + bars - 1;
    cout << (((fact[total_positions] * inverse[total_positions - stars]) % mod) * inverse[stars]) % mod << nl;
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