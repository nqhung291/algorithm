/*
Given a sequence of integers a1,…,an. Compute the longest subsequence (elements are not necessarily continous) in which elements are in an increasing orders.

Input
Line 1 contains an integer n (1≤n≤104)
Line 2 contains n integers a1,…,an
Output
Write the length of the longest subsequence found.
Inp:
10
7 2 3 7 5 4 2 1 9 6
Out:
4
*/
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
