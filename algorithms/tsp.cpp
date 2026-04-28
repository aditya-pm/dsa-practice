#include <iostream>
#include <vector>
using namespace std;

int n = 4;
int dist[10][10] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}};

int minCost = 1e9;

void tsp(int curr, int count, int cost, vector<bool>& visited) {
    // all cities visited → return to start
    if (count == n) {
        minCost = min(minCost, cost + dist[curr][0]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            tsp(i, count + 1, cost + dist[curr][i], visited);
            visited[i] = false;  // backtrack
        }
    }
}

int main() {
    vector<bool> visited(n, false);

    visited[0] = true;  // start from city 0
    tsp(0, 1, 0, visited);

    cout << "Minimum cost: " << minCost;
}