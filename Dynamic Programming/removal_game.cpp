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
ll dp[5000][5000][2];
ll rec(ll i, ll j, ll turn, vector<ll> &a)
{
    if (i > j)
        return 0;
    if (dp[i][j][turn] != -1)
        return dp[i][j][turn];

    ll ans;
    if (turn == 0)
    {
        ll op1 = a[i] + rec(i + 1, j, 1, a);
        ll op2 = a[j] + rec(i, j - 1, 1, a);
        ans = max(op1, op2);
    }
    else
    {
        ll op1 = rec(i + 1, j, 0, a);
        ll op2 = rec(i, j - 1, 0, a);
        ans = min(op1, op2);
    }
    return dp[i][j][turn] = ans;
}
void memoization()
{
    memset(dp, -1, sizeof(dp));
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    cout << rec(0, n - 1, 0, a) << nl;
}

void tabulation()
{
    memset(dp, 0, sizeof(dp));
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    // initialization
    for (ll i = 0; i < n; i++)
        dp[i][i][0] = a[i];

    // transistion
    for (ll len = 2; len <= n; len++)
    {
        for (ll j = len - 1; j < n; j++)
        {
            ll i = j - len + 1;
            dp[i][j][0] = max(a[i] + dp[i + 1][j][1], a[j] + dp[i][j - 1][1]);
            dp[i][j][1] = min(dp[i + 1][j][0], dp[i][j - 1][0]);
        }
    }
    cout << dp[0][n - 1][0] << nl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        // memoization();
        tabulation();
    }
    return 0;
}