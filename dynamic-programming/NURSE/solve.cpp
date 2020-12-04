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
int n,k1,k2, dp[mxN][mxN]; // dp[day][worked day on current period] = ways

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k1 >> k2;
  dp[1][0] = 1;
  dp[1][1] = 1;
  for (int i=2; i<=n;i++) {
    for (int j = k1; j<= k2; j++) {
      dp[i][0] += dp[i-1][j];
    }
    for (int j = 1; j <= k2; j++) {
      dp[i][j] += dp[i-1][j-1];
    }
  }
  int ans = dp[n][0];
  for (int j = k1; j <= k2; j++) {
    ans += dp[n][j];
  }
  cout << ans % 1000000007 << endl;
  return 0;
}
