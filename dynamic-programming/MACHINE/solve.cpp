#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long      ull;
typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          ii;
typedef vector<ii>              vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;

const int mxN = 2000010;
int dp[mxN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vii p(n+1);
  for (int i=1;i<=n;i++) {
    int s,t;
    cin >> s >> t;
    p[i] = make_pair(s,t);
    // dp[t] = max(dp[t], t-s);
  }

  sort(p.begin() + 1, p.end(), [](ii& a, ii& b) {
    return a.second < b.second;
  });
  int j = 1;
  for (int i=1; i<=p[n].second; i++) {
    dp[i] = dp[i-1];
    while (i == p[j].second) {
      dp[i] = max(dp[i], p[j].second - p[j].first);
      j++;
    }
  }

  int ans = -1;
  for (int i = 1; i<=n; i++) {
    if (dp[p[i].first - 1] != 0) {
      ans = max(ans, dp[p[i].first - 1] + p[i].second - p[i].first);
    }
  }
  cout << ans << endl;
  return 0;
}
