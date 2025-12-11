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
    ll n, s, b = -1, c;
    cin >> n >> s;
    map<ll, set<ll>> m;
    vll a(n);
    rep(i, n)
    {
        cin >> a[i];
        m[a[i]].insert(i + 1);
    }
    rep(i, n)
    {
        if (m.find(s - a[i]) != m.end())
        {
            if (s - a[i] == a[i])
            {
                if (m[s - a[i]].size() > 1)
                {
                    b = i + 1;
                    for (auto j : m[s - a[i]])
                    {
                        if (j != b)
                        {
                            c = j;
                            break;
                        }
                    }
                }
            }
            else
            {
                b = i + 1;
                c = *m[s - a[i]].begin();
                break;
            }
        }
        if (b != -1)
            break;
    }
    if (b != -1)
        cout << b << ' ' << c << nl;
    else
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