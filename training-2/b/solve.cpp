#include <bits/stdc++.h>
using namespace std;

int n, k;
long long res;
map<int, int> m;
priority_queue<int> q;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  while (n--) {
    int x, l;
    cin >> x >> l;
    q.push(x);
    m.emplace(x, l);
  }

  int capacity = k;
  int prev = 0;
  while (!q.empty()) {
    int t = q.top();
    if (capacity >= m[t]) {
      q.pop();
      capacity -= m[t];
      res += abs(t - prev);
      prev = t;
    } else if (0 < capacity && capacity < m[t]) {
      m[t] = m[t] - capacity;
      capacity = 0;
      res += abs(t - prev);
      prev = t;
    } 
    if (capacity == 0) {
      res += abs(prev);
      prev = 0;
      capacity = k;
    }
  }
  cout << res << '\n';
  return 0;
}
