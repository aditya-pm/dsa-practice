#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);  // track visited nodes
    queue<int> q;

    q.push(start);  // step 1: push start
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();  // get front
        q.pop();               // remove it

        cout << node << " ";  // visit

        // explore neighbors
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}