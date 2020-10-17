#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
int n;
int val[mxN];
int pos[mxN];
int ans[mxN];

void solve() {
  pos[n-1] = -1;
  ans[n-1] = -1;
  for (int i = n-2; i >= 0; i--) {
    if (val[i] > val[i+1]) {
      int biggerPos = pos[i+1];
      if (biggerPos == -1) {
        pos[i] = -1;
      } else {
        while (1) {
          if (val[i] > val[biggerPos]) {
            if (pos[biggerPos] == -1) {
              pos[i] = -1;
              break;
            } else {
              biggerPos = pos[biggerPos];
            }
          } else {
            pos[i] = biggerPos;
            break;
          }
        }
      }
    } else {
      pos[i] = i+1;
    }
    if (pos[i] == -1) {
      ans[i] = n-1-i-1;
    } else {
      ans[i] = pos[i] - i - 2;
    }
  }
}

void printAns(int size) {
  for (int i = 0; i < size; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }
  solve();
  printAns(n);
  return 0;
}
