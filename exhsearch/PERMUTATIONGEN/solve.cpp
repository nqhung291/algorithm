#include <bits/stdc++.h>
using namespace std;

int n, a[10001], mark[10001], x[10001];
bool found_same = false, has_result = false;

void print() {
  for (int i = 1; i<=n; i++) {
    cout << x[i] << ' ';
  }
  cout << endl;
}

void solve(int k) {
  if (k > n) {
    if (found_same) {
      print();
      has_result = true;
      return;
    }
    found_same = true;
  };
  for (int i = 1; i <= n; i++) {
    if (has_result) return;
    if (!mark[i] && (found_same || i == a[k])) {
      mark[i] = 1;
      x[k] = i;
      solve(k+1);
      mark[i] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  solve(1);
  if (!has_result) cout << -1 << endl; 
  return 0;
}
