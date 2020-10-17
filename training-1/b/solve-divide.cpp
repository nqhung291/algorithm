#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;
int n, a[mxN];

long maxLeft(int l, int r) {
  long maxL = 0, sum = 0;
  for(int i=r; i>=l; i--) {
    sum += a[i];
    maxL = max(maxL, sum);
  }
  return maxL;
}

long maxRight(int l, int r) {
  long maxR = 0, sum = 0;
  for(int i=l; i<=r; i++) {
    sum += a[i];
    maxR = max(maxR, sum);
  }
  return maxR;
}

long maxSeq(int l, int r) {
  if (l==r) return a[l];
  int m = (l+r)/2;
  long maxL = maxSeq(l,m);
  long maxR = maxSeq(m+1,r);

  long maxML = maxLeft(l,m);
  long maxMR = maxRight(m+1,r);
  long maxM = maxML + maxMR;  
  return max(max(maxL, maxR), maxM);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  cout << maxSeq(0, n-1);
}
