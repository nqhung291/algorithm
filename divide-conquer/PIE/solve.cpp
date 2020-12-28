/*
My birthday is coming up and traditionally I'm serving pie. Not just one pie, no, I have a number N of them, of various tastes and of various sizes. F of my friends are coming to my party and each of them gets a piece of pie. This should be one piece of one pie, not several small pieces since that looks messy. This piece can be one whole pie though. My friends are very annoying and if one of them gets a bigger piece than the others, they start complaining. Therefore all of them should get equally sized (but not necessarily equally shaped) pieces, even if this leads to some pie getting spoiled (which is better than spoiling the party). Of course, I want a piece of pie for myself too, and that piece should also be of the same size. What is the largest possible piece size all of us can get? All the pies are cylindrical in shape and they all have the same height 1, but the radii of the pies can be different.

Input
One line with a positive integer: the number of test cases. Then for each test case:

One line with two integers N and F with 1≤N,F≤10000: the number of pies and the number of friends. 25% of tests has N,F≤10 and 25% of test has solution ≤0.1.
One line with N integers ri with 1≤ri≤10000: the radii of the pies.
Output
For each test case, output one line with the largest possible volume V such that me and my friends can all get a pie piece of size V. The answer should be given as a floating point number rounding to 6 digits after the floating point (accept error ≤10−6).
Inp: 
1
1 10000
3
Out:
0.002827
*/
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
