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
vi low(mxN), ids(mxN, -1);
// ids: thu tu cac dinh da duyet trong DFS
// low: chi so nho nhat ma at co the cham duoc boi backedges
int cnt = 0;
int bridges = 0;
int out_edges_cnt = 0;
vector<bool> is_ap(mxN, false); // is articulation points

// at: current vertice
// parent: previous vertice
void dfs(int root, int at, int parent) {
  if (parent == root) out_edges_cnt++;
  low[at] = ids[at] = cnt++;
  for (int i = 0; i < (int) adj[at].size(); i++) {
    int to = adj[at][i];
    if (to == parent) continue; // khong xet quay lai dinh ngay truoc
    if (ids[to] == -1) {
      dfs(root, to, at);
      low[at] = min(low[at], low[to]);
      if (low[to] >= ids[at]) {
       is_ap[at] = true;
      }
    } else {
      low[at] = min(low[at], ids[to]); // khi node to is visited, thi no co kha nang co ids lower than current low[at]
    }
    if (low[to] > ids[at]) {
      bridges++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int v1,v2;
  for (int i=1; i<= m; i++) {
    cin >> v1 >> v2;
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }

  for (int i = 1; i <= n; i++) {
    if (ids[i] == -1) {
      out_edges_cnt = 0;
      dfs(i, i, -1);
      is_ap[i] = out_edges_cnt > 1;
    }
  }
  int ap_cnt = 0;
  for (int i = 1; i <= n; i++) {
    ap_cnt += (int) is_ap[i];
  }
  cout << ap_cnt << " " << bridges << endl;
  return 0;
}
