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
int dp[100001][100];
int rec(int i, int sum, vector<int> &a)
{
    if (sum == 0)
        return 1;
    if (i < 0)
        return 0;
    if (dp[sum][i] != -1)
        return dp[sum][i];

    int op1 = 0, op2 = rec(i - 1, sum, a);
    if (a[i] <= sum)
        op1 = rec(i - 1, sum - a[i], a);
    return (op1 | op2);
}
void memoizationSolution()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    set<int> st;
    for (int sum = 100000; sum >= 1; sum--)
        if (rec(n - 1, sum, a))
            st.insert(sum);
    cout << st.size() << nl;
    for (int x : st)
        cout << x << " ";
    cout << nl;
}
void tabulationSolution()
{
    memset(dp, 0, sizeof(dp));
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    // initialization:
    // when sum is 0 dp[0][i] will be true
    for (int i = 0; i < n; i++)
        dp[0][i] = 1;

    // when u have just first element in array thendp[a[0]][0]=1
    dp[a[0]][0] = 1;
    st.insert(a[0]);

    for (int sum = 1; sum <= 100000; sum++)
    {
        for (int i = 1; i < n; i++)
        {
            dp[sum][i] = dp[sum][i - 1];
            if (a[i] <= sum)
                dp[sum][i] |= dp[sum - a[i]][i - 1];
            if (dp[sum][i])
                st.insert(sum);
        }
    }
    cout << st.size() << nl;
    for (int x : st)
        cout << x << " ";
    cout << nl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        // memoizationSolution();
        tabulationSolution();
    }
    return 0;
}