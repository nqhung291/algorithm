/** 
The BACP is to design a balanced academic curriculum by assigning periods to courses in a way that the academic load of each period is balanced . There are N courses 1,2,…,N that must be assigned to M periods 1,2,…,M. Each courses i has credit ci and has some courses as prerequisites. The load of a period is defined to be the sum of credits of courses assigned to that period. The prerequisites information is represented by a matrix AN×N in which Ai,j = 1 indicates that courses i must be assigned to a period before the period to which the course j is assigned. Compute the assignment such that the maximum load for all periods is minimal.
Input
Line 1 contains N and M (2≤N≤16,2≤M≤5)
Line 2 contains c1,c2,…,cN
Line i+2(i=1,…,N) contains the ith line of the matrix A
Output
Unique line contains that maximum load for all periods of the solution found

Input:
6 2
4 4 4 4 2 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 0 0
0 0 1 0 0 0
1 0 0 0 0 0
Output:
12
*/

#include <bits/stdc++.h>
using namespace std;

int m, n, credit[17], p[17][17], best = INT_MAX; // n course, m period
int course[17];
int load[6];

void solve(int k) {
  if (k > n) {
    int max_load = 0;
    for (int i=1;i<=m;i++) {
      max_load = max(max_load, load[i]);
    }
    best = min(best, max_load);
    return;
  }
  for (int i=1;i<=m;i++) {
    course[k] = i;
    if (load[i] + credit[k] < best) {
      load[i] += credit[k];
      solve(k+1);
      load[i] -= credit[k];
    }
  }
  
} 

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  for (int i=1;i<=n;i++) {
    cin >> credit[i];
  }
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      cin >> p[i][j];
    }
  }
  solve(1);
  cout << best << endl;

  return 0;
}
