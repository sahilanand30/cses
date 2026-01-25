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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), ans;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    multiset<int> first, second;
    for (int i = 0; i < k; i++)
        second.insert(a[i]);

    while (first.size() < ((k + 1) / 2))
    {
        auto it = second.begin();
        first.insert(*it);
        second.erase(it);
    }
    ans.push_back(*first.rbegin());

    for (int i = k; i < n; i++)
    {
        auto it = first.find(a[i - k]);
        if (it != first.end())
            first.erase(it);
        else
        {
            it = second.find(a[i - k]);
            second.erase(it);
        }
        second.insert(a[i]);
        while (first.size() < ((k + 1) / 2))
        {
            auto it = second.begin();
            first.insert(*it);
            second.erase(it);
        }

        while (true)
        {
            if (second.empty())
                break;
            auto it = first.rbegin();
            auto jt = second.begin();
            if ((*it) > (*jt))
            {
                first.insert(*jt);
                second.erase(jt);
            }
            else
                break;
        }
        while (first.size() > ((k + 1) / 2))
        {
            auto it = --first.end();
            second.insert(*it);
            first.erase(it);
        }
        ans.push_back(*first.rbegin());
    }

    for (int x : ans)
        cout << x << ' ';
    cout << nl;
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