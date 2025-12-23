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
    ll n,x,ct=1;
    cin>>n;
    vector<pair<ll,ll>>v;
    for(ll i=0;i<n;i++){
        cin>>x;
        v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    for(ll i=1;i<n;i++)ct+=(v[i].second<v[i-1].second);
    cout<<ct<<nl;
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