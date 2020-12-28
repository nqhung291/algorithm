/*
The Kingdom ALPHA has n warehouses of golds located on a straight line and are numbered 1,2,...,n. The warehouse i has amount of ai (ai is non-negative integer) and is located at coordinate i (i=1,...,n). The King of ALPHA opens a competition for hunters who are responsible to find a subset of gold warehouses having largest total amount of golds with respect to the condition that the distance between two selected warehouses must be greater than or equal to L1 and less than or equal to L2.

Input
Line 1 contains n, L1, and L2 (1≤n≤100000,1≤L1≤L2≤n)
Line 2 contains n integers a1,a2,…,an
Output
Contains only one single integer denoting the total amount of golds of selected warehouses.
Inp:
6 2 3
3 5 9 6 7 4
Out:
19
*/
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

// DP type: Minimum (Maximum) path to reach a target
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
