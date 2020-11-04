#include <bits/stdc++.h>
using namespace std;

int n, a[10001], mark[10001], x[10001];
bool t = false;
bool stop = false;

void check() {
  for (int i = 1; i <= n; i++) {
    if (a[i] != x[i]) {
      t = false;
      return;
    };
  }
  t = true;
}

void print() {
  for (int i = 1; i<=n; i++) {
    cout << x[i] << ' ';
  }
  cout << endl;
}

void solve(int k) {
  if (k > n) {
    if (t) {
      print();
      stop = true;
      return;
    }
    check();
    return;
  };
  if (!stop) {
    for (int i = 1; i <= n; i++) {
      if (!mark[i]) {
        mark[i] = 1;
        x[k] = i;
        solve(k+1);
        mark[i] = 0;
      }
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
  return 0;
}
