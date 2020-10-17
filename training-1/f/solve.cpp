#include <bits/stdc++.h>
using namespace std;

const int mxN = 100;
int n;
string a[mxN];

void solve() {
  for (int i = 0; i < n; i++) {
    int l = a[i].length();
    if (l > 10) {  
      string temp = a[i].front() + to_string(l-2) + a[i].back();
      cout << temp << endl;
    } else {
      cout << a[i] << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  solve();
}
