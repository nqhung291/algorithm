/*
Example:
Input. <start time - end time>
3
12 25
15 26
1 40
Output
1
Explain: The new rankinging would be (runner 1, runner 0, runner 2). Thus only one pair (0, 1) would switch places
 
Input
5
0 6
2 7 
9 13
4 11
8 16
Output
4
Explain: The original rankinging is (0, 1, 3, 2, 4) sorted by finish time. The actual run time for the runners are respectively (6, 5, 4, 7, 8). Thus the new rankinging would be (2, 1, 0, 3, 4). There are 4 pairs that satisfy our condition: (0, 1), (0, 2), (1, 2), (2, 3)

*/
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

int n, ans = 0;

struct Runner {
  int index;
  int start;
  int finish;
  int duration;
  Runner(int _index, int _start, int _finish) {
    index = _index;
    start = _start;
    finish = _finish;
    duration = _finish - _start;
  }
};
vector<Runner> ranking;

void print_vector(vector<Runner>& _v) {
  for (Runner &r: _v) {
    cout << r.index << " ";
  }
  cout << endl;
}

void merge(int lo, int mid, int hi) {
  int l1 = mid - lo + 1;
  int l2 = hi - mid;
  int l = hi - lo + 1;
  // create temp array
  vector<Runner> L;
  vector<Runner> R;

  // copy temp array
  for (int i = 0; i < l1; i++) {
    L.pb(ranking[i + lo]);
  }
  for (int i = 0; i < l2; i++) {
    R.pb(ranking[i + mid + 1]);
  }

  // i: index of L, j: index of R, k: index of merged array
  int i = 0, j = 0;
  for (int k = lo; k <= hi; k++) {
    if (i < l1 && j < l2) {
      if (L[i].duration <= R[j].duration) {
        ranking[k] = L[i++];
      } else {
        ans += (l1 - i);
        ranking[k] = R[j++];
      }
    } else {
      if (i == l1) {
        ranking[k] = R[j++];
      } else {
        ranking[k] = L[i++];
      }
    }
  }
}

void merge_sort(int lo, int hi) {
  if (lo >= hi) return;
  int mid = (lo + hi) / 2;
  merge_sort(lo, mid);
  merge_sort(mid + 1, hi);
  merge(lo, mid, hi);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i<n; i++) {
    int t1,t2;
    cin >> t1 >> t2;
    ranking.pb(Runner(i, t1, t2));
  }
  // sort by end time
  sort(ranking.begin(), ranking.end(), [](Runner& a, Runner& b) {
    return a.finish < b.finish;
  });

  // sort by duration
  int lo = 0, hi = ranking.size() - 1;
  merge_sort(lo, hi);
  cout << ans << endl;

  return 0;
}
