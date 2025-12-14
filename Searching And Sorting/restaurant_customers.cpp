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
    ll n, a, b, ans = 0, curr = 0;
    cin >> n;
    vector<pair<int, int>> v;
    while (n--)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    multiset<int> endings;
    for (auto val : v)
    {
        curr++;
        endings.insert(val.second);
        while (!endings.empty() && (*endings.begin()) < val.first)
        {
            endings.erase(endings.begin());
            curr--;
        }
        ans = max(ans, curr);
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