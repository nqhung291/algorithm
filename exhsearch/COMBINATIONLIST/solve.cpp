#include <bits/stdc++.h>
using namespace std;

int n,m,k; // 9999, 9998, 987654321
unsigned long long fact[10001];
deque<int> v;

void calc_fact(int t) {
  fact[0] = fact[1] = 1;
  if (t > 1) {
    for (int i = 2; i <= t; i++) {
      fact[i] = i * fact[i-1];
      if (fact[i] > 1e9) return;
    }
  }
}

// calculate uCw
unsigned long long calc_comb(int u, int w) {
  if (fact[u] > 0) {
    return fact[u] / (fact[w] * fact[u-w]);
  }
  return 1e9+1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  calc_fact(n);

  if (k > (int) calc_comb(n, m)) {
    cout << -1 << endl;
    return 0;
  }

  for (int i=1;i<=n;i++) {
    v.push_back(i);
  }

  k--; // k is the index of next number
  for (int i=1; i<=m; i++) {
    int j = v.front();
    int index = -1;
    while (1) {
      if (i == m) {
        // cout << "k: " << k << endl;
        index = k;
        break;
      }
      int choose = calc_comb(n-j, m-i);
      if (k - choose < 0) {
        index = index < 0 ? 0 : index;
        break;
      }
      k -= choose;
      index = k;
      j++;
    }
    cout << v[index] << ' ';
    for (int h=0;h<=index;h++) {
      v.pop_front();
    }
  }
  return 0;
}
