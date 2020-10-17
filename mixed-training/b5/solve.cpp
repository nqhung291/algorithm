#include <bits/stdc++.h>
using namespace std;

const int mxN = 1000;
int n;
long arr[mxN][3];

void solve() {
  for (int i=0; i<n;i++) {
    long a = max(arr[i][0], arr[i][1]);
    long b = min(arr[i][0], arr[i][1]);
    long c = arr[i][2];
    if ((a-c)%b == 0) {
      cout << (a-c)/b + 1 << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j=0; j < 3; j++) {
      cin >> arr[i][j];
    }
  }
  solve();
}
