#include <bits/stdc++.h>
using namespace std;
/*
0 - 1 - 3 - 2 - 4 - 0
0 - 2 - 4 - 1 - 3
5 + 2 + 5 + 3 + 2 = 17
*/

int n, c[23][23], best = INT_MAX;
int mark[12];

void solve(int k, int prev, int distance) {
  if (k > n) {
    best = min(distance + c[prev][0], best);
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!mark[i]) {
      int test = distance + c[prev][i] + c[i][i+n];
      if (test < best) {
        mark[i] = 1;
        solve(k+1, i+n, test);
        mark[i] = 0;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i <= 2*n; i++) {
    for (int j = 0; j <= 2*n; j++) {
      cin >> c[i][j];
    }
  }
  solve(1, 0, 0);
  cout << best << endl;
  return 0;
}
