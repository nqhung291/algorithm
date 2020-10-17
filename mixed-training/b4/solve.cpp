#include <bits/stdc++.h>
using namespace std;

const int mxT = 1000;
string s[mxT];
int t;

void solve() {
  for (int i = 0; i < t; i++) {
    string str = s[i];
    stack<char> stk;
    for (int j = 0; j < (int) str.length(); j++) {
      if (stk.empty()) {
        stk.push(str.at(j));
      } else {
        if (stk.top() == '(' && str.at(j) == ')') {
          stk.pop();
        } else if (stk.top() == '[' && str.at(j) == ']') {
          stk.pop();
        } else if (stk.top() == '{' && str.at(j) == '}') {
          stk.pop();
        } else {
          stk.push(str.at(j));
        }
      }      
    }
    if (stk.empty()) cout << 1 << endl;
    else cout << 0 << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  for (int i=0; i<t; i++) {
    cin >> s[i];
  }
  solve();
}
