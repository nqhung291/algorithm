#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long      ull;
typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          pii;
typedef vector<pii>             vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;

int n, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  vi a(n);
  for (int& e: a) cin >> e;
  cin >> m;
  vii p(m);
  for (pii& e: p) {
    int i,j;
    cin >> i >> j;
    e = make_pair(i, j);
  }

  

  return 0;
}
