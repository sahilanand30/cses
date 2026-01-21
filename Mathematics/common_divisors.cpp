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
    int n, N=1000000, ans=1, x;
    cin>>n;
    vector<int>f(N+1,0);
    while(n--){
        cin>>x;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                f[i]++;
                if(i!=(x/i))f[x/i]++;
                if(f[i]==2)ans=max(ans,i);
                if(f[x/i]==2)ans=max(ans,x/i);
            }
        }
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