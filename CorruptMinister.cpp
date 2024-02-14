#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<pair<int, int>> edges;
    vector<int> mark(n, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    for (auto [u, v] : edges)
    {
        vector<bool> visited(n, 0);
        visited[u] = 1;
        queue<int> q;
        q.push(u);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto neighbor : adj[node])
            {
                if (!visited[neighbor] && !(node == u && neighbor == v) && !(node == v && neighbor == u))
                {
                    q.push(neighbor);
                    visited[neighbor] = 1;
                }
            }
        }

        if (visited[v] == 0)
        {
            mark[u]++;
            mark[v]++;
        }
    }
    int maxi = INT_MIN;
    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, mark[i]);
        mini = min(mini, mark[i]);
    }
    cout << maxi << " " << mini << endl;
}