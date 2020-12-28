/*
The director of a hospital want to schedule a working plan for a nurse in a given period of N consecutive days 1,..., N. Due to the policy of the hospital, each nurse cannot work all the days 1,..., N. Instead, there must be days off in which the nurse need to take a rest. A working plan is a sequence of disjoint working periods. A working period of a nurse is defined to be a sequence of consecutive days on which the nurse must work and the length of the working period is the number of consecutive days of that working period. The hospital imposes two constraints:

Each nurse can take a rest only one day between two consecutive working periods. it means that if the nurse takes a rest today, then she has to work tomorrow (1)
The length of each working period must be greater or equal to K1 and less than or equal to K2 (2)
The director of the hospital want to know how many possible working plans satisfying above constraint?
Input
The input consists of one line which contains 3 positive integers N,K1,K2(N≤1000,K1<K2≤400)
Output
The output consists of only one single integer M modulo 109+7 where M is the total working plans satisfying the above constraints.
Inp: 6 2 3
Out: 4
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
