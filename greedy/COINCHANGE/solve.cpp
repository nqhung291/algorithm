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

int n;
int coins[] = {1,5,10,50,100,500}; 
int ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int pay = 1000 - n;
  for (int i = 5; i >= 0; i--) {
    int num = pay / coins[i];
    pay -= num * coins[i];
    ans += num;
  }
  cout << ans << endl;
  return 0;
}
