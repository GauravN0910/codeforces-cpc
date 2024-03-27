#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    if (visited[node])
    {
        return;
    }
    visited[node] = 1;
    for (auto x : adj[node])
    {
        dfs(x, adj, visited);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(m + n + 1, vector<int>());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        count += k;
        while (k--)
        {
            int x;
            cin >> x;
            adj[m + i].push_back(x - 1);
            adj[x - 1].push_back(m + i);
        }
    }
    int ans = -1;
    vector<bool> visited(m + n, false);
    if (count == 0)
    {
        cout << n << endl;
    }
    else
    {
        for (int i = m; i < m + n; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited);
                ans++;
            }
        }
        cout << ans << endl;
    }
}