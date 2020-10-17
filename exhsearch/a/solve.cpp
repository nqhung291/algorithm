#include <bits/stdc++.h>
using namespace std;

int n, m; // cur: current city
int minEdge = INT_MAX;
int minDist = INT_MAX; // min distance
int dist = 0; // current distance
int start = 1;

void solve(map<int, int> *edges, bool *visited, int* path, int k) { // k: k-th visited city
  for (int v = 1; v <= n; v++) {
    if (!visited[v] && edges[path[k-1]].find(v) != edges[path[k-1]].end()) {
      path[k] = v;
      visited[v] = true;
      dist += edges[path[k-1]][path[k]];
      if (k == n) {
        if (dist + edges[path[k]][1] < minDist) {
          minDist = dist + edges[path[k]][1];
        }
      } else {
        int estimateDist = dist + (n - k + 1) * minEdge;
        if (estimateDist < minDist) {
          solve(edges, visited, path, k+1);
        } 
      }
      dist -= edges[path[k-1]][path[k]];
      visited[v] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  map<int, int> edges[n+1];
  bool visited[n+1];
  int path[n+1];

  while (m--) {
    int u,v,w;
    cin >> u >> v >> w;
    edges[u][v] = w;
    if (w < minEdge) minEdge = w;
  }

  for (int i = 0; i <= n; i++) {
    visited[i] = false;
  }
  visited[start] = true;
  path[start] = start;
  solve(edges, visited, path, 2);
  cout << minDist << endl;
  return 0;
}
