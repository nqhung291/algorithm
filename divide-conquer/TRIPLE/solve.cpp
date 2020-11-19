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

int n,K,a[5001];
int cnt[100001];
long long res = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> K;
  for (int i=1;i<=n;i++) {
    cin >> a[i];
  }
  sort(a+1, a+n);
  for (int j=1;j<=n;j++) {
    cnt[a[j-1]]++;
    for (int k=j+1;k<=n;k++) {
      if (K - a[j] - a[k] > 0) {
        res += cnt[K - a[j] - a[k]];
      }
    }
  }
  cout << res << endl;
  return 0;
}
