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
    string s;
    int n, k, ans = 30;
    cin >> n >> k;
    vector<bitset<30>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < k; j++)
            v[i][j] = s[j] - '0';
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans = min(ans, (int)(v[i] ^ v[j]).count());
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