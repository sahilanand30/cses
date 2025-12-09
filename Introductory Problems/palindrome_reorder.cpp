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
    deque<char> dq;
    string s;
    cin >> s;
    ll n = s.size(), ct = 0;
    map<char, ll> m;
    for (char c : s)
        m[c]++;
    char odd = '#';
    for (auto val : m)
    {
        if (val.second & 1)
        {
            ct++;
            odd = val.first;
        }
    }
    if (n % 2 == 0)
    {
        if (ct > 0)
        {
            cout << "NO SOLUTION\n";
            return;
        }
        for (auto val : m)
        {
            ll x = val.second / 2;
            while (x--)
            {
                dq.push_back(val.first);
                dq.push_front(val.first);
            }
        }
        for (char c : dq)
            cout << c;
        cout << nl;
    }
    else
    {
        if (ct != 1)
        {
            cout << "NO SOLUTION\n";
            return;
        }
        ll x = m[odd] / 2;
        dq.push_back(odd);
        while (x--)
        {
            dq.push_back(odd);
            dq.push_front(odd);
        }
        for (auto val : m)
        {
            if (val.first != odd)
            {
                ll x = val.second / 2;
                while (x--)
                {
                    dq.push_back(val.first);
                    dq.push_front(val.first);
                }
            }
        }
        for (char c : dq)
            cout << c;
        cout << nl;
    }
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