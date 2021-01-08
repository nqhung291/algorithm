#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long      ull;
typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          ii;
typedef vector<ii>             vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;

const int mxN = 100010;
int n, t[mxN];
int ans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  sort(t+1, t+n+1, greater<int>());
  for (int i = 1; i <= n; i++) {
    int finish_date = i + t[i] + 1;
    ans = max(ans, finish_date); 
  }
  cout << ans << endl;
  return 0;
}
