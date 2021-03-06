/*
Farmer John has built a new long barn, with N (2≤N≤100,000) stalls. The stalls are located along a straight line at positions x1,…,xN (0≤xi≤1,000,000,000).

His C (2≤C≤N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Input
t – the number of test cases, then t test cases follows.

Line 1: Two space-separated integers: N and C
Lines 2…N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Input: 
1
5 3
1
2
8
4
9
Output:
3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxN = 100010;
int t;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    int n,c;
    cin >> n >> c;
    vector<int> x(n);
    for (int& e: x) cin >> e;
    sort(x.begin(), x.end());

    auto f = [&](int limit) {
      int prev = 0;
      int cow = 1;
      for (int i=1;i<n;i++) {
        if (x[i] - x[prev] >= limit) {
          prev = i;
          cow++;
          if (cow == c) return true;
        }
      }
      return false;
    };

    int lo = 0, hi = x.back(), ans = -1;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (f(mid)) {
        ans = mid;
        lo = mid+1;
      } else {
        hi = mid-1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
