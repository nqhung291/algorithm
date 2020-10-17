#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;
int n, a[mxN];
long long m = 1e9+7;
long long res = 0;

void solve() {
  for (int i = 0; i < n; i++) {
    res = (res + a[i] % m) % m;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  solve();
  cout << res << endl;
}
