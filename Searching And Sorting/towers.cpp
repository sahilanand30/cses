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
    ll n, x, ans = 0;
    cin >> n;
    multiset<ll> st;
    while (n--)
    {
        cin >> x;
        auto it = st.upper_bound(x);
        if (it == st.end())
        {
            ans++;
            st.insert(x);
        }
        else
        {
            st.erase(it);
            st.insert(x);
        }
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