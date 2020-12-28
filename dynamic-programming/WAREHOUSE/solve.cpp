/*
A truck is planned to arrive at some stations among N stations 1,2,...,N located on a line. Station i (i=1,…,N) has coordinate i and has following information

ai: amount of goods
ti: pickup time duration for taking goods
The route of the truck is a sequence of stations x1<x2<...<xk (1≤xj≤N,j=1,…,k). Due to technical constraints, the distance between two consecutive stations that the truck arrives xi and xi+1 is less than or equal to D and the total pickup time duration cannot exceed T. Find a route for the truck such that total amount of goods picked up is maximal.
Input
Line 1: N,T,D (1≤N≤1000,1≤T≤100,1≤D≤10)
Line 2: a1,…,aN(1≤ai≤10)
Line 3: t1,…,tN(1≤ti≤10)
Inp: 
6 6 2
6 8 5 10 11 6
1 2 2 3 3 2
Out: 24
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
