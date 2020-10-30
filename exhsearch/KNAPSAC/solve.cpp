#include <bits/stdc++.h>
using namespace std;

int n,b, a[30], c[30], best = 0;

void solve(int k, int A, int C) {
  if (k > n) {
    if (A <= b) best = max(best, C);
    return;
  }
  // khong chon vat dung
  solve(k+1, A, C);
  if (A + a[k] <= b) { // chon vat dung
    solve(k+1, A + a[k], C + c[k]);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> b;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> c[i];
  }

  solve(0, 0, 0);
  cout << best << endl;
  return 0;
}
