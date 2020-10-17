#include <bits/stdc++.h>
using namespace std;

unsigned long long a,b;
unsigned long long n = 1e9+7;

void solve() {
  if (a > n || b > n) {
    unsigned long long a0 = a%n;
    unsigned long long b0 = b%n;
    cout << (a0+b0)%n << endl;
  } else {
    cout << (a+b)%n << endl;
  }
}

int main() {
  cin >> a >> b;
  solve();
}
