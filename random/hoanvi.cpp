#include <bits/stdc++.h>
using namespace std;

int n;

void printResult(int* a) {
  for (int i = 0; i < n; i++) {
    cout << a[i];
  }
  cout << endl;
}

void hoanvi(int k, int* a, int* d) {
  for (int i = 0; i < n; i++) {
    if (!d[i]) {
      a[k] = i;
      d[i] = 1;
      if (k == n-1) {
        printResult(a);
      } else {
        hoanvi(k+1, a, d);
      }
      d[i] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int a[n];
  int d[n];
  fill(a, a+n, 0);
  fill(d, d+n, 0);
  hoanvi(0, a, d);

  return 0;
}
