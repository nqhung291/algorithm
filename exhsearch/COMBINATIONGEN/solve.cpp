/*
Cho 1 một chuỗi tổ hợp C độ dài m với các thành phần nằm trong tập {1,2,…,n}. Tìm chuỗi tổ hợp kế tiếp của chuỗi C trong thứ tự từ điển.

Input
Dòng đầu 2 số nguyên dương n,m≤104.

Dòng thứ 2 ghi m số nguyên dương ≤n cách nhau bởi dấu cách.

Output
Ghi ra chuỗi C trên một dòng duy nhất, các thành phần cách nhau bởi dấu cách. Nếu không tồn tại thì ghi ra -1.
*/
#include <bits/stdc++.h>
using namespace std;

int n,m,s[10001],d[10001],mark[10001];
bool found, has_result;
int max_num;

void print_array(int* arr, int l) {
  for (int i=1;i<=l;i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

bool check(int i, int k) {
  return (!found && s[k] == i) || (found && !mark[i]);
}

// l: length of result
void solve(int l, int k) {
  if (k > l) {
    if (!found) {
      found = true;
      return; 
    }
    has_result = true;
    return;
  }
  for (int i = d[k-1]+1; i <= n-l+k; i++) {
    if (has_result) return;
    if (check(i,k)) {
      d[k] = i;
      mark[i] = 1;
      solve(l, k+1);
      mark[i] = 0;
    }
  }
}

void solve2() {
  max_num = n;
  for (int i=m; i>=1;i--) {
    if (s[i] < max_num) {
      s[i]++;
      for (int j=i+1; j<=m; j++) {
        s[j] = s[j-1]+1;
      }
      print_array(s, m);
      return;
    }
    max_num--;
  }
  cout << -1 << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i=1; i<=m; i++) {
    cin >> s[i];
  }
  // solve(m, 1);
  // if (!has_result) {
  //   cout << -1 << endl;
  //   return 0;
  // }
  // for (int i=1;i<=m;i++) {
  //   cout << d[i] << ' ';
  // }
  
  solve2();    
  return 0;
}