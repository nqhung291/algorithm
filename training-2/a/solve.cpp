#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vvi;

void solve() {
  for (int i = 0; i < (int) vvi.size(); i++) {
    vector<int> hist = vvi[i];
    int n = hist.size();
    long long maxRect = 0; // max rectangle
    int height; // top of stack
    stack<int> pos;
    int j = 0;
    while (j < n) {
      if (pos.empty() || hist[pos.top()] <= hist[j] ) {
        pos.push(j++);
      } else {
        height = hist[pos.top()];
        pos.pop();
        int length = pos.empty() ? j : (j - pos.top() - 1);
        long long rect = height * length;
        if (rect > maxRect) maxRect = rect;
      }
    }
    while (!pos.empty()) {
      height = hist[pos.top()];
      pos.pop();
      int length = pos.empty() ? j : (j - pos.top() - 1);
      long long rect = height * length;
      if (rect > maxRect) maxRect = rect;
    }
    cout << maxRect << '\n';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (1) {
    int n;
    cin >> n;
    if (n == 0) break;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      v.push_back(num);
    }
    vvi.push_back(v);
  }
  solve();
  return 0;
}
