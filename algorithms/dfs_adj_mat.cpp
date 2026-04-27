#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int n) {
    cout << node << " ";
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, adj, visited, n);
        }
    }
}

int main() {
    int n, start;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    cin >> start;

    vector<bool> visited(n, false);

    dfs(start, adj, visited, n);
}