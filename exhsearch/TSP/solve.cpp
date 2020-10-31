#include <bits/stdc++.h>
using namespace std;

int n, m, c[21], d[21][21], best = INT_MAX;
int visited[21];
int min_distance = INT_MAX;

void solve(int k, int prev, int distance) {
  if (k > n) {
    if (d[prev][1] != 0){
      best = min(best, distance + d[prev][1]);
      return;
    }
  }
  for (int i = 2; i <= n; i++) {
    if (!visited[i] && d[prev][i] != 0) {
      visited[i] = 1;
      int test = distance + d[prev][i];
      if (test + (n-k+1) * min_distance < best) {
        solve(k+1, i, test);
      }  
      visited[i] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (m--) {
    int c1,c2, dis;
    cin >> c1 >> c2 >> dis;
    min_distance = min(min_distance, dis);
    d[c1][c2] = dis;
  }
  solve(2, 1, 0);
  cout << best << endl;
  return 0;
}
