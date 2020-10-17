#include <iostream>

using namespace std;

int main() {
  unsigned long long a,b;
  cin >> a;
  cin >> b;
  if (a > 100 || b > 100) {
    unsigned long long a1 = a / 10;
    unsigned long long a0 = a % 10;
    unsigned long long b1 = b / 10;
    unsigned long long b0 = b % 10;
    unsigned long long c1 = (a0 + b0) / 10;
    unsigned long long c0 = (a0 + b0) % 10;
    cout << a1 + b1 + c1 << c0;
  } else {
    cout << a + b;
  }
}