#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int N,K,Q,d[MAX];
int R[MAX][MAX], load[MAX], visited[MAX], visited_cnt = 0;
int ans = 0;

void printRes() {
  for (int i=1; i<MAX;i++) {
    if (R[i][1] == 0) break;
    for (int j=0; j<MAX; j++) {
      cout << R[i][j] << ' ';
      if (j > 0 && R[i][j] == 0) break;
    }
    cout << endl;
  }
  cout << "--------------" << endl;
}

bool checkJ(int i, int j, int v) {
  if (v > 0 && visited[v]) return false;
  if (load[i] + d[v] > Q) return false;
  if (v == 0 && i == K && visited_cnt < N-K) return false;
  return true;
}

void solve_j(int i, int j) {
  if (i > K) {
    // printRes();
    ans++;
    return;
  }
  if (R[i][j-1] == 0) {
    solve_j(i+1, 2);
    return;
  }
  for (int v=0; v<=N; v++) {
    if (!checkJ(i, j, v)) continue;
    R[i][j] = v;
    visited[v] = 1;
    visited_cnt += (v > 0);
    load[i] += d[v];
    solve_j(i, j+1);
    visited[v] = 0;
    visited_cnt -= (v > 0);
    load[i] -= d[v];
  }
}

// i: truck index
void solve_i(int i) {
  if (i > K) {
    solve_j(1, 2);
    return;
  }
  for (int v = R[i-1][1] + 1; v <= N; v++) {
    if (v > 0 && visited[v]) continue;
    if (load[i] + d[v] > Q) continue;
    R[i][1] = v;
    visited[v] = 1;
    load[i] += d[v];
    solve_i(i+1);
    visited[v] = 0;
    load[i] -= d[v];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K >> Q;
  for (int i=1;i<=N;i++) {
    cin >> d[i];
  }

  solve_i(1);
  cout << ans << endl;
  return 0;
}
