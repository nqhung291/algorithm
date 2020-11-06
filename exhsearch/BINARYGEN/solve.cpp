#include <bits/stdc++.h>
using namespace std;

int n, d[(int)1e4];
string s, res = "";
bool same = false, has_result = false;

void solve(int k) {
  if (k == n) {
    if (!same) {
      same = true;
    } else {
      for (int i=0;i<n;i++) {
        res += to_string(d[i]);
      }
      has_result = true;
    }
    return;
  }
    for (int i=0;i<=1;i++) {
      if (has_result) return;
      if (d[k] == i || same) {
        d[k] = i;
        solve(k+1);
      }
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  for (int i=0;i<n;i++) {
    d[i] = s[i] - '0';
  }
  solve(0);
  if (has_result) {
    cout << res << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
