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
int rec(int i, int x, vector<int> &price, vector<int> &page)
{
    if (i < 0)
        return 0;

    int op1 = 0, op2 = rec(i - 1, x, price, page);
    if (price[i] <= x)
        op1 = page[i] + rec(i - 1, x - price[i], price, page);
    return max(op1, op2);
}
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> page(n), price(n);
    for (ll i = 0; i < n; i++)
        cin >> price[i];
    for (ll i = 0; i < n; i++)
        cin >> page[i];
    // Recursive Way
    // cout<<rec(n-1x,price,page)<<nl;

    // Iterative way
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for (int j = 0; j <= x; j++)
        if (price[0] <= j)
            dp[0][j] = page[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            int op1 = 0, op2 = 0;
            if (i - 1 >= 0 && price[i] <= j)
                op1 = page[i] + dp[i - 1][j - price[i]];
            if (i - 1 >= 0)
                op2 = dp[i - 1][j];
            dp[i][j] = max(op1, op2);
        }
    }
    cout << dp[n - 1][x] << nl;
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