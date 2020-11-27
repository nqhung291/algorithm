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

int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vii pts(n);
  for (pii& e: pts) {
    int x,y;
    cin >> x >> y;
    e = make_pair(x,y);
  }


  return 0;
}
