#include <bits/stdc++.h>
using namespace std;

long double EPS = 1e-6;
int t;
long double pi = 3.14159265358979323846;
vector<long double> res;

bool check(long double x, long double *s, int F, int N) {
  if (x == 0) return false;
  int p = 0;
  for (int i=0; i < N; i++) {
    p += s[i] / x; 
  }
  return p >= F+1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    int N,F;
    cin >> N >> F;
    long double s[N];
    long double smax = 0;
    for (int i=0;i<N;i++) {
      int r;
      cin >> r;
      s[i] = pi*r*r;
      smax = max(s[i], smax);
    }
    long double lo = 0.0, hi = smax;
    while (hi - lo >= EPS) {
      long double mid = (lo + hi)/2;
      if (check(mid, s, F, N)) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    res.push_back(lo);
  }

  for (int i = 0; i < (int) res.size();i++) {
    cout << fixed << setprecision(6) << res[i] << endl;
  }

  return 0;
}
