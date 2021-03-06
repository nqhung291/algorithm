/*
A subsequence of a given sequence S=S1,…,Sn is obtained by removing some elements from S. Given two sequence of integers X=(X1,…,Xn) and Y=(Y1,…,Ym). Find the longest common subsequence of X and Y.

Input
Line 1 contains n and m (1≤n,m≤104)
Line 2 contains X1,…,Xn
Line 3 contains Y1,…,Ym
Output
Write the length of the longest subsequence of the given sequences
Inp:
7 10
3 7 2 5 1 4 9
4 3 2 3 6 1 5 4 9 7
Out:
5
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

const int mxN = 10010;
int n,m;
int dp[mxN][mxN]; // dp[i][j] save longest common subsequence between string a[0,i] and b[0,j] 

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vi a(n+1);
  vi b(m+1);
  for (int i=1; i<=n; i++) cin >> a[i];
  for (int i=1; i<=m; i++) cin >> b[i];

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      if (a[i] == b[j]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}
