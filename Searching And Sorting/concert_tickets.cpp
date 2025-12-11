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
    ll n, m, x;
    cin >> n >> m;
    multiset<ll> st;
    while (n--)
    {
        cin >> x;
        st.insert(x);
    }
    while (m--)
    {
        cin >> x;
        if (st.empty())
        {
            cout << "-1\n";
            continue;
        }
        auto it = st.lower_bound(x);
        if (it == st.end())
        {
            it--;
            cout << (*it) << nl;
            st.erase(it);
        }
        else
        {
            if ((*it) == x)
            {
                cout << x << nl;
                st.erase(it);
            }
            else if ((*it) > x)
            {
                if (it == st.begin())
                    cout << "-1\n";
                else
                {
                    it--;
                    cout << (*it) << nl;
                    st.erase(it);
                }
            }
        }
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