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
vi component(mxN, -1);

void dfs(int v, int ans) {
  if (component[v] != - 1) return;
  component[v] = ans;
  for (int i=0; i< (int) adj[v].size(); i++) {
    dfs(adj[v][i], ans);
  }
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

  int ans = 0;
  for (int i = 1; i<=n; i++) {
    if (component[i] == -1) {
      dfs(i, ans);
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
