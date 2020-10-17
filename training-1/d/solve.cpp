#include <bits/stdc++.h>
using namespace std;

unsigned long long a,b;
unsigned long long n=1e9+7;
unsigned long long res = 1;

// recursive method:
int power(long long a, unsigned long long b) {
  if (b == 0) return 1;
  if (b % 2 == 1) return power(a, b-1) * a % n;
  a = power(a, n/2);
  return a * a % n;
}

// iterative method:
void solve() {
  a %= n;
  while (b > 0) {
    if (b % 2 == 1) {
      res = (res * a) % n;
    }
    a = (a * a) % n;
    b /= 2;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;
  // solve();
  power(a, b);
  cout << res;
}
