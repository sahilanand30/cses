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
    int n, x;
    cin >> n >> x;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int dp[n + 1][x + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int sum = 0; sum <= x; sum++)
        {
            if (sum == 0)
                dp[i][sum] = 1;
            else
            {
                int op1 = (v[i] > sum) ? 0 : dp[i][sum - v[i]];
                int op2 = (i == 1) ? 0 : dp[i - 1][sum];
                dp[i][sum] = (op1 + op2) % mod;
            }
        }
    }
    cout << dp[n][x];
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