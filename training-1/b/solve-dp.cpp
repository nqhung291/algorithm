#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;
int n; 
long a[mxN], s[mxN];

void solve() {
  s[0] = a[0];
  long res = s[0];
  for(int i=1; i<n; i++) {
    s[i] = max(s[i-1] + a[i], a[i]);
    res = max(res, s[i]);
  }
  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  solve();
}
