#include <bits/stdc++.h>
using namespace std;

int n;

void solve(int k, int* a) {
  if (a[k] < n) {
    a[k]++;
    
  }

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    a[i] = t;
  }
  
  solve(n, a);

  return 0;
}
