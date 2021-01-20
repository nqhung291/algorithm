#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define each(x, a) for (auto& x: a)
#define all(c) (c).begin(), (c).end()
typedef unsigned long long      ull;
typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          ii;
typedef vector<ii>              vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;

void read(char* file) {
  freopen(file, "r", stdin);
}

void write(char* file) {
  freopen(file, "w", stdout);
}

struct edge {
  int u,v;
  int weight;

  edge(int _u, int _v, int _weight) {
    u = _u;
    v = _v;
    weight = _weight;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

    int n,q;
    read("./input_0.txt");
    cin >> n >> q;
    vi a(n);
    each(e, a) {
      cin >> e;
      
    } 
    int d[51][51];
    vector<vector<edge>> adj;
    for (int i = 0; i<=n; i++) {
      for (int j = 0; j <=n; j++) {
        cin >> d[i][j];
      }
    }
  int pay = 1000 - n;
  for (int i = 5; i >= 0; i--) {
    int num = pay / coins[i];
    pay -= num * coins[i];
    ans += num;
  }



  return 0;
}