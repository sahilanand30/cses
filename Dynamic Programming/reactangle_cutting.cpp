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
int rec(int a, int b, vector<vector<int>> &dp)
{
    if (a == b)
        return 0;
    if (a == 1)
        return b - 1;
    if (b == 1)
        return a - 1;
    if (dp[a][b] != -1)
        return dp[a][b];

    int ans = INT_MAX;
    for (int i = 1; i < a; i++)
        ans = min(ans, 1 + rec(i, b, dp) + rec(a - i, b, dp));
    for (int j = 1; j < b; j++)
        ans = min(ans, 1 + rec(a, j, dp) + rec(a, b - j, dp));
    return dp[a][b] = ans;
}
void memoization()
{
    int a, b, ans = 0;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
    cout << rec(a, b, dp) << nl;
}
void tabulation()
{
    ll a, b;
    cin >> a >> b;
    vector<vector<ll>> dp(a + 1, vector<ll>(b + 1, 0));

    // initialization
    for (ll i = 2; i <= b; i++)
        dp[1][i] = i - 1;
    for (ll i = 2; i <= a; i++)
        dp[i][1] = i - 1;
    for (ll i = 1; i <= min(a, b); i++)
        dp[i][i] = 0;

    // transisions
    for (ll i = 2; i <= a; i++)
    {
        for (ll j = 2; j <= b; j++)
        {
            if (i == j)
                continue;
            ll ans = INT_MAX;
            for (ll k = 1; k < i; k++)
                ans = min(ans, 1 + dp[k][j] + dp[i - k][j]);
            for (ll k = 1; k < j; k++)
                ans = min(ans, 1 + dp[i][k] + dp[i][j - k]);
            if (dp[i][j] == 0)
                dp[i][j] = ans;
            dp[i][j] = min(dp[i][j], ans);
        }
    }
    cout << dp[a][b] << nl;
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