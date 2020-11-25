#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int mxN = 510;
int t;
int m, k, p[mxN];
ll sum;
bool flag[mxN];
string ans = "";

bool check(ll limit) {
  memset(flag, 0, sizeof(flag));
  int cnt = k; // index of current scriber
  ll curr = 0; // number of page for current scriber
  for (int i=m;i>=1;i--) { // start from m-th books
    if (curr + p[i] > limit || i < cnt) { // if number of pages exceeds limit or the number of books remains < number of scriber remains
      curr = p[i];
      cnt--;
      flag[i] = true;
      if (cnt == 0) return false;
    } else {
      curr += p[i];
    }
  }
  return true;
}

void solve() {
  ll lo = 0, hi = sum, mid;
  for (int i=1;i<=m;i++) {
    if (lo < p[i]) lo = p[i];
  }
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (check(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  check(lo);
  for (int i=1; i<=m;i++) {
    cout << p[i];
    if (i < m) cout << " ";
    if (flag[i]) cout << "/ ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while (t--) {
    cin >> m >> k;
    for (int i=1;i<=m;i++) {
      cin >> p[i];
      sum += p[i];
    }
    solve();
  }

  return 0;
}
