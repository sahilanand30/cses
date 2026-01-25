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
ll f(ll firstSum, ll secondSum, ll tar, ll n, ll m)
{
    return ((n * tar) - firstSum) + (secondSum - (m * tar));
}
void solve()
{
    ll n, k, firstSum = 0, secondSum = 0;
    cin >> n >> k;
    vector<ll> a(n), ans;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    multiset<ll> first, second;
    for (ll i = 0; i < k; i++)
    {
        secondSum += a[i];
        second.insert(a[i]);
    }

    while (first.size() < ((k + 1) / 2))
    {
        auto it = second.begin();
        firstSum += (*it);
        first.insert(*it);
        secondSum -= (*it);
        second.erase(it);
    }
    ans.push_back(f(firstSum, secondSum, *first.rbegin(), first.size(), second.size()));

    for (ll i = k; i < n; i++)
    {
        auto it = first.find(a[i - k]);
        if (it != first.end())
        {
            firstSum -= (*it);
            first.erase(it);
        }
        else
        {
            it = second.find(a[i - k]);
            secondSum -= (*it);
            second.erase(it);
        }
        secondSum += a[i];
        second.insert(a[i]);
        while (first.size() < ((k + 1) / 2))
        {
            auto it = second.begin();
            firstSum += (*it);
            first.insert(*it);
            secondSum -= (*it);
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
                firstSum += (*jt);
                first.insert(*jt);
                secondSum -= (*jt);
                second.erase(jt);
            }
            else
                break;
        }
        while (first.size() > ((k + 1) / 2))
        {
            auto it = --first.end();
            secondSum += (*it);
            second.insert(*it);
            firstSum -= (*it);
            first.erase(it);
        }
        ans.push_back(f(firstSum, secondSum, *first.rbegin(), first.size(), second.size()));
    }

    for (ll x : ans)
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