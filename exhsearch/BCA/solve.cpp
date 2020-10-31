#include <bits/stdc++.h>
using namespace std;

// m: teacher, n: course
int m, n, c[31][31], p[11][31], best = INT_MAX;
int load[11];
vector<int> teach[11];

bool is_conflict(int i, int k) {
  for (int j = 0; j < (int) teach[i].size(); j++) {
    if (c[k][teach[i][j]] == 1) {
      return true;
    }
  }
  return false;
}

void solve(int k) {
  if (k > n) {
    int curr_best = INT_MIN;
    for (int i = 1; i <= m; i++) {
      curr_best = max(curr_best, load[i]);
    }
    best = min(best, curr_best);
    return;
  }
  for (int i = 1; i <= m; i++) {
    if (p[i][k] == 1 && !is_conflict(i,k)) {
      teach[i].push_back(k);
      load[i]++;
      if (load[i] < best) {
        solve(k+1);
      }
      teach[i].pop_back();
      load[i]--;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    int t;
    cin >> t;
    while (t--) {
      int k;
      cin >> k;
      p[i][k] = 1;
    }
  }
  int k;
  cin >> k;
  while (k--) {
    int c1,c2;
    cin >> c1 >> c2;
    c[c1][c2] = c[c2][c1] = 1;
  }

  solve(1);
  cout << best << endl;

  return 0;
}
