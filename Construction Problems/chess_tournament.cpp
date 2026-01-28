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
/*
LOGIC:
- Greedy approach: always match player with most remaining games first
- Use priority queue to always pick player with max remaining games
- For each player, match with next available player who hasn't played with them
- If at any point we can't satisfy a player's requirement, answer is IMPOSSIBLE
*/
void solve()
{
    int n;
    cin >> n;
    vector<int> req(n); // required games for each player
    ll totalGames = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> req[i];
        totalGames += req[i];
    }
    
    // Total games must be even (each game involves 2 players)
    if (totalGames % 2 != 0)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    vector<pair<int, int>> ans;
    vector<set<int>> played(n); // track who played with whom
    
    // Priority queue: {remaining games, player index}
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (req[i] > 0)
            pq.push({req[i], i});
    }
    
    while (!pq.empty())
    {
        auto [games1, p1] = pq.top();
        pq.pop();
        
        if (games1 == 0)
            continue;
        
        // Collect top players to match with p1
        vector<pair<int, int>> temp;
        int matched = 0;
        
        while (!pq.empty() && matched < games1)
        {
            auto [games2, p2] = pq.top();
            pq.pop();
            
            // Check if they haven't played together
            if (played[p1].find(p2) == played[p1].end())
            {
                // Match them
                played[p1].insert(p2);
                played[p2].insert(p1);
                ans.push_back({p1 + 1, p2 + 1});
                matched++;
                games2--;
                
                if (games2 > 0)
                    temp.push_back({games2, p2});
            }
            else
            {
                temp.push_back({games2, p2});
            }
        }
        
        // Put back remaining players
        for (auto p : temp)
        {
            pq.push(p);
        }
        
        // If we couldn't match enough games for p1
        if (matched < games1)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    
    cout << ans.size() << nl;
    for (auto val : ans)
        cout << val.first << ' ' << val.second << nl;
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