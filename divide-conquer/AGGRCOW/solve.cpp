#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxN = 100010;
int t;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    int n,c;
    cin >> n >> c;
    vector<int> x(n);
    for (int& e: x) cin >> e;
    sort(x.begin(), x.end());

    auto f = [&](int limit) {
      int prev = 0;
      int cow = 1;
      for (int i=1;i<n;i++) {
        if (x[i] - x[prev] >= limit) {
          prev = i;
          cow++;
          if (cow == c) return true;
        }
      }
      return false;
    };

    int lo = 0, hi = x.back(), ans = -1;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (f(mid)) {
        ans = mid;
        lo = mid+1;
      } else {
        hi = mid-1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
