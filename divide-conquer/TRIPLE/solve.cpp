/*
Given a sequence of positive integers a=(a1,…,aN) and a positive integer K. Compute the number Q of triple (i,j,k) such that 1≤i<j<k≤N and ai+aj+ak=K.

Input
The input consists of following lines:

Line 1 contains N and K (1≤N≤5000,1≤K≤105).
Line 2 contains a1,…,aN (1≤ai≤105)
Output
Write the value Q.

Input: 
6 12
2 3 4 1 6 7
Output: 
3
*/
#include <bits/stdc++.h>
using namespace std;

int n,k,a[5001],res=0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  if (n<3) {
    cout << 0 << endl;
    return 0;
  }
  for (int i=1;i<=n;i++) {
    cin >> a[i];
  }
  sort(a, a+n);
  for (int i=1;i<=n-2;i++) {
    int l=i+1, r=n;
    while (l < r) {
      if (a[l] + a[r] == k - a[i]) {
        l++; r--;
        res++;
      } else if (a[l] + a[r] > k - a[i]) {
        r--;
      } else {
        l++;
      }
    }
  }
  cout << res << endl;
  return 0;
}
