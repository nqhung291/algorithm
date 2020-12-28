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
int n,m;
vi adj[mxN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int v1,v2;
  for (int i=1; i<= m; i++) {
    cin >> v1 >> v2;
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }
  
  return 0;
}
