#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
typedef unsigned long long      ull;
typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          ii;
typedef vector<ii>             vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;

const int mxN = 10000;

struct edge {
  int u,v;
  int weight;

  edge(int _u, int _v, int _weight) {
    u = _u;
    v = _v;
    weight = _weight;
  }
};

struct union_find {
  vector<int> parent;
  union_find(int n) {
    parent = vi(n);
    for (int i = 0; i < n; i++) {
      // khoi tao nut parent cua moi dinh bang chinh no
      parent[i] = i;
    }
  };

  int find(int x) {
    if (parent[x] == x) return x;
    parent[x] = find(parent[x]);
    return parent[x];
  }

  void unite(int x, int y) {
    parent[find(x)] = find(y);
  }
};

// short implementation of union find
// int p[mxN];
// int find(int x) {
//   return p[x] == x ? x : p[x] = find(p[x]);
// }
// void unite(int x, int y) {
//   p[find(x)] = find(y);
// }
// for (int i = 0; i < mxN; i++) {
//   p[i] = i;
// }

vector<vector<edge>> weight_adj; // graph with weight

int n, m; // number of vertical, edges
vvi adj; // non weight graph
vi visited(mxN, 0);

void bfs(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (!visited[v]) {
        q.push(v);
        visited[v] = 1;
      }
    }
  }
}

void dfs(int u) {
  if (visited[u]) return;
  visited[u] = 1;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    dfs(v);
  }
}

vi dist(mxN, INT_MAX);
void dijkstra(int start) {
  dist[start] = 0;
  priority_queue<ii, vii, greater<ii>> pq;
  pq.push(MP(dist[start], start));
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for (int i = 0; i < weight_adj[u].size(); i++) {
      int v = weight_adj[u][i].v;
      int w = weight_adj[u][v].weight;
      if (w + dist[u] < dist[v]) {
        dist[v] = w + dist[u];
        pq.push(MP(dist[v], v));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  weight_adj[0].push_back(edge(0,1,2));
  weight_adj[0].push_back(edge(0,2,3));


  return 0;
}
