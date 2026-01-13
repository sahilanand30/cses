/*
Author: Sahil Anand
Find me on: https://linktr.ee/sahilanand30
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define nl endl

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
vector<pair<int, int>> path;
bool found;

void dfs(int i, int j, vector<vector<char>> &g, vector<vector<int>> &minYou, vector<vector<int>> &minMonster,
         vector<vector<bool>> &vis, int parI, int parJ, vector<vector<pair<int, int>>> &parent)
{
    if (found)
        return;

    int n = g.size(), m = g[0].size();
    vis[i][j] = true;
    parent[i][j] = {parI, parJ};

    if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
    {
        found = true;
        int I = i, J = j;
        while (parent[I][J] != make_pair(I, J))
        {
            path.push_back({I, J});
            auto [pi, pj] = parent[I][J];
            I = pi;
            J = pj;
        }
        path.push_back({I, J});
        reverse(path.begin(), path.end());

        cout << "YES\n"
             << path.size() - 1 << nl;
        for (int k = 1; k < path.size(); k++)
        {
            if (path[k].first < path[k - 1].first)
                cout << 'U';
            else if (path[k].first > path[k - 1].first)
                cout << 'D';
            else if (path[k].second < path[k - 1].second)
                cout << 'L';
            else
                cout << 'R';
        }
        cout << nl;
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
            g[ni][nj] == '.' && !vis[ni][nj] &&
            minYou[ni][nj] < minMonster[ni][nj])
        {
            dfs(ni, nj, g, minYou, minMonster, vis, i, j, parent);
            if (found)
                return;
        }
    }
}

void solve()
{
    path.clear();
    found = false;

    int n, m, I, J;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> minMonster(n, vector<int>(m, INT_MAX)), minYou(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));

    queue<array<int, 3>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'A')
            {
                I = i;
                J = j;
            }
        }
    }

    // BFS from You
    minYou[I][J] = 0;
    q.push({I, J, 0});
    while (!q.empty())
    {
        auto [x, y, d] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int ni = x + dx[k], nj = y + dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                g[ni][nj] == '.' && minYou[ni][nj] == INT_MAX)
            {
                minYou[ni][nj] = d + 1;
                q.push({ni, nj, d + 1});
            }
        }
    }

    // BFS from Monsters
    while (!q.empty())
        q.pop();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 'M')
            {
                minMonster[i][j] = 0;
                q.push({i, j, 0});
            }

    while (!q.empty())
    {
        auto [x, y, d] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int ni = x + dx[k], nj = y + dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                g[ni][nj] == '.' && minMonster[ni][nj] == INT_MAX)
            {
                minMonster[ni][nj] = d + 1;
                q.push({ni, nj, d + 1});
            }
        }
    }

    dfs(I, J, g, minYou, minMonster, vis, I, J, parent);

    if (!found)
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1;
    while (t--)
        solve();

    return 0;
}
