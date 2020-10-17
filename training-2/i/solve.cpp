#include <bits/stdc++.h>
using namespace std;

string s;
string sAns = "";
string sTemp;
int ans = 0;
int maxBracket = 0;
int n = 0;
stack<char> stk;

void solve() {
  for (int i = 0; i < (int) s.length(); i++) {
    if (stk.empty()) {
      if (maxBracket != 0) {
        sTemp = "";
        maxBracket = 0;
      }
      stk.push(s.at(i));
    } else {
      if (stk.top() == '[' && s.at(i) == ']') {
        maxBracket++;
        sTemp = '[' + sTemp + ']';
        stk.pop();
        if (maxBracket > ans) {
          ans = maxBracket;
          sAns = sTemp;
        }
      } else if (stk.top() == '(' && s.at(i) == ')') {
        sTemp = '(' + sTemp + ')';
        stk.pop();
      } else {
        if (maxBracket != 0) {
          sTemp = "";
          maxBracket = 0;
        }
        stk.push(s.at(i));
      }
    }
  }
  cout << ans << '\n';
  cout << sAns << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  solve();

  return 0;
}
