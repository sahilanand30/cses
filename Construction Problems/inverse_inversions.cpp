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
    ll n,k,threshold;
    cin>>n>>k;
    if(n==1){
        cout<<"1\n";
        return;
    }
    deque<ll>dq;
    for(ll i=1;i<n;i++)if(((i*(i-1))/2)<=k)threshold=i;
    // cout<<threshold<<nl;return;
    ll tar = k-((threshold*(threshold-1))/2),ct=0;
    for(ll i=n;i>=1 && threshold>0;i--,threshold--)dq.push_back(i);
    for(ll i=dq.back()-1;i>=2;i--)dq.push_front(i);
    for(ll x : dq){
        if(ct==tar)cout<<"1 ";
        ct++;
        cout<<x<<' ';
    }
    if(ct==tar)cout<<"1 ";
    cout<<nl;
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

/*
n = 5
k = 1 => [1,2,3,5,4]
k = 2 => [1,2,5,3,4]
k = 3 => [1,5,2,3,4]
k = 4 => [5,1,2,3,4]

k = 5 => [5,1,2,4,3]
*/