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

const int mxN = 1010;
int a[mxN], t[mxN];
int dp[mxN][mxN]; // dp[station][time] = goods

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N,T,D;
  cin >> N >> T >> D;
  for (int i=1;i<=N;i++) {
    cin >> a[i];
  }
  for (int i=1;i<=N;i++) {
    cin >> t[i];
  }
  int ans = -1;
  dp[1][t[1]] = a[1];
  for (int i=2;i<=N;i++) {
    dp[i][t[i]] = a[i];
    for (int j=1;j<=D;j++) {
      if (j < i) {
        for (int k=t[i-j]; k <= T - t[i]; k++) {
          dp[i][k + t[i]] = max(dp[i][k + t[i]], dp[i-j][k] + a[i]);
          ans = max(ans, dp[i][k + t[i]]);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
