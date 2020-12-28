/*
An engineer needs to schedule a machine to run on some given periods 1,…,n to produce a chemical product C. Each period i is represented by a starting time point si and terminating time point ti (si<ti). Due to a technical constraint, the machine must run on exactly two periods that are not overlap (two periods i and j are not overlap if ti<sj or tj<si). If the machine is runned on the period i, then the amount of C it will produce is equal to the duration of the period i (which is equal to ti−si). Help the engineer to select two not-overlap periods to run the machine such that the amount of C produced is maximal.

Input
Line 1: contains the positive integer n (2≤n≤2⋅106)
Line i+1: contains two positive integer si and ti (1≤si<ti≤2⋅106)
Output
The output consists of only one single integer which is the amount of product C the machine will produce in the two selected periods. In case there is no solution (there does not exist two periods that are not overlap), the output contains the value -1.
Inp:
5
8 12
6 11
3 9
2 5
1 4
Out:
8
*/
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
