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
    ll n,k;
    cin>>n>>k;
    if(((n+k-1)/k)>k){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    deque<ll>dq;
    vector<ll>tmp;
    for(ll i=1;i<=n;i++){
        tmp.push_back(i);
        if(tmp.size()==k){
            reverse(tmp.begin(),tmp.end());
            for(ll x : tmp)dq.push_front(x);
            tmp.clear();
        }
    }
    reverse(tmp.begin(),tmp.end());
    for(ll x : tmp)dq.push_front(x);
    for(ll x : dq)cout<<x<<' ';cout<<nl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}