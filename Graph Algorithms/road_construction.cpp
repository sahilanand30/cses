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
int findParent(int a, vector<int> &par)
{
    if (par[a] == a)
        return a;
    return par[a] = findParent(par[a], par);
}
void Union(int a, int b, vector<int> &par, vector<int> &componentSize, multiset<int> &st, multiset<int> &largestSize)
{
    int A = findParent(a, par), B = findParent(b, par);
    if (A != B)
    {
        if (componentSize[A] > componentSize[B])
            swap(A, B);
        par[A] = B;
        st.erase(A);
        largestSize.erase(largestSize.find(componentSize[A]));
        componentSize[B] += componentSize[A];
        largestSize.insert(componentSize[B]);
    }
}
void solve()
{
    multiset<int> st, largestComponent;
    int n, m, a, b;
    cin >> n >> m;
    vector<int> par(n + 1), componentSize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        largestComponent.insert(1);
        componentSize[i] = 1;
        st.insert(i);
    }
    while (m--)
    {
        cin >> a >> b;
        Union(a, b, par, componentSize, st, largestComponent);
        cout << (st.size()) << " " << (*largestComponent.rbegin()) << nl;
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