#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long      ull;
typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          pii;
typedef vector<pii>             vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;

const int mxN = 100010;
ull a[mxN];
ull dp[mxN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, l1, l2;
  cin >> n >> l1 >> l2;
  for (int i=1; i<=n;i++) cin >> a[i];

  dp[1] = a[1];
  ull ans = dp[1];
  for (int i=2;i<=n;++i) {
    dp[i] = a[i];
    for (int j=l1; j<=l2; ++j) {
      if (j < i) {
        dp[i] = max(dp[i], dp[i-j] + a[i]);
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
