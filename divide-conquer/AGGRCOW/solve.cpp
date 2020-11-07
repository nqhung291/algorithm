#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    int n,c;
    cin >> n >> c;
    vector<int> x(n);
    for (int &e: x) cin >> e;
    sort(x.begin(), x.end());
    
    auto f = [&](int k) {
      int i = 0;
      for (int t=1;t<=c;t++) { // xet tung con bo
        if (i >= n) return false; // het chuong
        int post = x[i]; // dat bo t vao chuong i
        while (i<n && x[i] - post < k) i++;
      }
      return true;
    };
    
    int l=0, h=x.back(), ans=-1;
    while (l<=h) {
      int m = (l+h)/2;
      if (f(m)) {
        ans = m;
        l = m + 1;
      } else h = m-1;
    }
    cout << ans << endl;
  }

  return 0;
}
