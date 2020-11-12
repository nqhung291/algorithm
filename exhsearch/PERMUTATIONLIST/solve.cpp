#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> v; 
unsigned long long fact[10001];

void calc_fact(int t) {
  fact[0] = fact[1] = 1;
  if (t > 1) {
    for (int i = 2; i <= t; i++) {
      fact[i] = i * fact[i-1];
      if (fact[i] > 1e9) return;
    }
  }
}

int get_number_from_index(int index) {
  if (index > n-1) return -1;
  int num = v[index];
  v.erase(v.begin() + index);
  return num;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  calc_fact(n);

  for (int i=1;i<=n;i++) {
    v.push_back(i);
  }
  k--;
  for (int i=1;i<=n;i++) {
    int index = fact[n-i] > 0 ? k / fact[n-i] : 0;
    int num = get_number_from_index(index);
    if (num == -1) {
      cout << -1 << endl;
      return 0;
    }
    cout << num << ' ';
    k -= index * fact[n-i];
  }

  return 0;
}
