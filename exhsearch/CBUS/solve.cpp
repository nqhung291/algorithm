#include <bits/stdc++.h>
using namespace std;

int n,k,d[44][44], best = INT_MAX;
int mark[44];

// k: so nguoi da len + xuong thanh cong
// curr: so nguoi tren xe
// prev: diem truoc
void solve(int i, int curr, int prev, int sum) {
  if (i > 2*n) {
    best = min(best, sum + d[prev][0]);
    return;
  }
  for (int j = 1; j <= 2*n; j++) {
    if (mark[j]) continue; // da don roi
    if (curr + (j <= n) > k) continue; // qua tai
    if (j > n && !mark[j-n]) continue; // chua don
    if (sum+d[prev][j] < best) {
      mark[j] = 1;
      solve(i+1, curr+(j>n?-1:1), j, sum+d[prev][j]);
      mark[j] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i <= 2*n; i++) {
    for (int j = 0; j <= 2*n; j++) {
      cin >> d[i][j];
    }
  }

  solve(1, 0, 0, 0);
  cout << best << endl;
  return 0;
}
