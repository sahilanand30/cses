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
    ll dx[4] = {-1, 0, 1, 0};
    ll dy[4] = {0, -1, 0, 1};
    ll n, m, I, J;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<pair<ll, ll>>> parent(n, vector<pair<ll, ll>>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> v[i][j];
            parent[i][j] = {i, j};
            if (v[i][j] == 'A')
                I = i, J = j;
        }
    }
    queue<pair<ll, ll>> q;
    q.push({I, J});
    while (!q.empty())
    {
        ll sz = q.size();
        while (sz--)
        {
            I = q.front().first, J = q.front().second;
            q.pop();
            for (ll k = 0; k < 4; k++)
            {
                ll i = I + dx[k], j = J + dy[k];
                if (i >= 0 && i < n && j >= 0 && j < m && (v[i][j] == '.' || v[i][j] == 'B') && parent[i][j] == make_pair(i, j))
                {
                    q.push({i, j});
                    parent[i][j] = {I, J};
                }
            }
        }
    }
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            if (v[i][j] == 'B')
                I = i, J = j;
    vector<pair<ll, ll>> path;
    while (true)
    {
        path.push_back({I, J});
        if (parent[I][J] == make_pair(I, J))
            break;
        ll newI = parent[I][J].first, newJ = parent[I][J].second;
        I = newI, J = newJ;
    }
    if (v[I][J] == 'A')
    {
        cout << "YES\n";
        reverse(path.begin(), path.end());
        n = path.size();
        cout << n - 1 << nl;
        for (ll i = 1; i < n; i++)
        {
            if (path[i].first < path[i - 1].first)
                cout << 'U';
            else if (path[i].first > path[i - 1].first)
                cout << 'D';
            else if (path[i].second < path[i - 1].second)
                cout << 'L';
            else
                cout << 'R';
        }
    }
    else
        cout << "NO\n";
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