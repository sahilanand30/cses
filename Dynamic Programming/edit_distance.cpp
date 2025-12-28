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
int dp[5001][5001];
int rec(int i, int j, string &a, string &b)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if(dp[i][j]!=-1)return dp[i][j];

    int ans = 1000000;
    ans = min(ans, 1 + rec(i, j - 1, a, b));
    ans = min(ans, 1 + rec(i - 1, j, a, b));
    ans = min(ans, (a[i]!=b[j]) + rec(i - 1, j - 1, a, b));
    return dp[i][j] = ans;
}
void solve()
{
    string a, b;
    cin >> a >> b;
    memset(dp,-1,sizeof(dp));
    cout << rec(a.size()-1, b.size()-1, a, b) << nl;
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