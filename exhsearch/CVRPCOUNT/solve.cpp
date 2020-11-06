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

int n,k,q,d[11],x[11]; // n clients, k trucks, capacity q, x: nghiem client - truck
int load[6],visited[6]; // load: current load of truck i, visited: number of client truck i visited
int res = 0;
int t = 0; // t: number of truck is visited at least one client

void print_array(int* arr, int l) {
  for (int i=1;i<=l;i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}
// c: client c-th
void solve(int c) {
  if (c > n) {
    print_array(x,n);
    res++;
    return;
  }
  for (int i=1;i<=k;i++) {
    if (visited[i] >= n-(c-1)-(k-t-1)) continue;
    if (load[i] + d[c] > q) continue;
    x[c] = i;
    t += (visited[i] == 0);
    visited[i]++;
    load[i]+=d[c];
    solve(c+1);
    visited[i]--;
    t -= (visited[i] == 0);
    load[i]-=d[c];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> q;
  for (int i=1;i<=n;i++) {
    cin >> d[i];
  }
  solve(1);
  cout << res << endl;
  return 0;
}
