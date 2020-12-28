#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long      ull;
typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          ii;
typedef vector<ii>             vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;

const int mxN = 100010;
int n,m;
vi adj[mxN];
int colors[mxN];

bool dfs(int v, int color) {
  if (colors[v] != 0) return colors[v] == color;
  colors[v] = color;
  for (int i = 0; i < adj[v].size(); i++) {
    if (!dfs(adj[v][i], -color)) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i=1; i<=m; i++) {
    int v1,v2;
    cin >> v1 >> v2;
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }

  for (int i = 1; i <= n; i++) {
    if (colors[i] == 0 && !dfs(i, 1)) {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << 1 << endl;
  return 0;
}
