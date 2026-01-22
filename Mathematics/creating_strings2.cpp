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

    string s;
    cin >> s;
    vector<ll> f(26, 0);
    for (char c : s)
        f[c - 'a']++;

    ll ans = fact[s.size()];
    for (ll x : f)
        ans = (ans * inverse[x]) % mod;
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