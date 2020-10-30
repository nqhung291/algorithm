#include <bits/stdc++.h>
using namespace std;
/*
0 - 1 - 3 - 2 - 4 - 0
0 - 2 - 4 - 1 - 3
5 + 2 + 5 + 3 + 2 = 17
*/

int n, c[23][23], best = INT_MAX;
int mark[23];

void solve(int k, int sum) {

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
  solve(1, 0);
  return 0;
}
