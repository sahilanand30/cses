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
set<string>st;
void rec(int i, string &s){
    if(i==0){
        st.insert(s);
        return;
    }
     st.insert(s);

    for(ll j=i-1;j>=0;j--){
        swap(s[i],s[j]);
        rec(i-1,s);
        
        swap(s[i],s[j]);
        rec(i-1,s);
    }
}
void solve()
{
    string s;
    cin>>s;
    rec(s.size()-1,s);
    cout<<st.size()<<nl;
    for(string S : st)cout<<S<<nl;
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