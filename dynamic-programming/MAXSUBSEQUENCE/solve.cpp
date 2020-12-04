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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int dp[n+1];
  vi a(n+1);
  for (int i=1; i<=n; i++) {
    cin >> a[i];
  }
  dp[0] = 0;
  int ans = INT_MIN;
  for (int i=1;i<=n;i++) {
    dp[i] = max(a[i], dp[i-1] + a[i]);
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
