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
    ll n, x, a;
    cin >> n >> x;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    for (ll i = 0; i < n; i++)
    {
        ll j = i + 1, k = n - 1;
        while (j < k)
        {
            ll sum = v[i].first + v[j].first + v[k].first;
            if (sum == x)
            {
                cout << v[i].second + 1 << " " << v[j].second + 1 << " " << v[k].second + 1 << nl;
                return;
            }
            else if (sum < x)
                j++;
            else
                k--;
        }
    }
    cout << "IMPOSSIBLE\n";
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