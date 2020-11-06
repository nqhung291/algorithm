/*
A fleet of K identical trucks having capacity Q need to be scheduled to delivery pepsi packages from a central depot 0 to clients 1,2,…,n. Each client i requests d[i] packages.

Each client is visited exactly by one route
Total number of packages requested by clients of each truck cannot exceed its capacity
Each truck must visit at least one client
Goal
Compute number R of solutions
Note that: the orders of clients in a route is important, e.g., routes 0 -> 1 -> 2 -> 3 -> 0 and 0 -> 3-> 2 -> 1 -> 0 are different.

Input
Line 1: n,K,Q (2≤n≤10,1≤K≤5,1≤Q≤20)
Line 2: d[1],...,d[n] (1≤d[i]≤10)
Output
R mod 1e9+7

Example
Input
3 2 4
3 2 1
Output
4
=======
k <= n
*/
#include <bits/stdc++.h>
using namespace std;

int n,k,q,d[11],mark[11]; // n clients, k trucks, capacity q
int r[6][11];
int low, high;
int res = 0;

// i: xe thu i, lc: limit client, cc: current client, p: current package, f: so client da duoc phan cho cac xe truoc
void find_client(int i, int lc, int cc, int p, int f) {
  if (cc > lc) {
    // TODO
    solve(i+1, f+lc);
    return;
  }
  for (int c=1; c<=n; c++) {
    if (!mark[c]) {
      if (p + d[c] < q) { // co the toi uu them duoc
        mark[c] = 1;
        r[i][cc] = c;
        find_client(i, lc, cc+1, p + d[c], f);
        mark[c] = 0;
      }
    }
  }
}

// i: xe thu i
// f: so client da duoc phan cho cac xe truoc
void solve(int i, int f) {
  if (i > k) {
    res++;
    return;
  };
  if (i == k) {
    low = n - f;
    high = n - f;
  } else {
    low = 1;
    high = n - f - (k - i);
  }
  
  for (int j=low;j<=high;j++) {
    // tim clients phu hop voi xe thu i
    find_client(i, j, 0, 0, f);
    // solve(i+1, f+j);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> q;
  for (int i=1;i<=n;i++) {
    cin >> d[i];
  }
  solve(1, 0);
  cout << res << endl;

  return 0;
}
