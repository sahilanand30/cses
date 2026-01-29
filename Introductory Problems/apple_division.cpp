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
    ll n,ans=1e15,total=0;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        total+=a[i];
    }
    ll lim = 1<<n;
    for(ll i=0;i<lim;i++){
        ll sum=0;
        for(ll bit=0;bit<n;bit++)if((i&(1<<bit))!=0)sum+=a[bit];
        ans=min(ans,abs(total-sum-sum));
    }
    cout<<ans<<nl;
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