#include <bits/stdc++.h>
using namespace std;

int n;
int a[10001];
int dp[10001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for (int i=1;i<=n;i++) {
    cin >> a[i];
  }
  dp[1] = 0;
  int ans = dp[1];
  for (int i=2;i<=n;i++) {
    int maxval = 0;
    for (int j=1;j<i;j++) {
      if (a[j] < a[i]) {
        maxval = max(maxval, dp[j]);
      }
    }
    dp[i] = maxval + 1;
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
