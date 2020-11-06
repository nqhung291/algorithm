/*
Write C program that reads an integer value N from stdin, prints to stdout the number Q ways to assign values 1, 2, …, 9 to characters I,C,T,H,U,S,K (characters are assigned with different values) such that: ICT−K62+HUST=N
Input: Unique line contains an integer N (1≤N≤105)
Output: Write the value Q
Input: 2000
Output: 20
*/

#include <bits/stdc++.h>
using namespace std;

// I C T H U S K 
int n,c[8],mark[10],res=0;

void solve(int k) {
  if (k > 7) {
    if (100*c[1]+10*c[2]+2*c[3]+1000*c[4]+100*c[5]+10*c[6]-100*c[7]-62 == n) {
      res++;
    }
    return;
  }
  for (int i=1;i<=9;i++) {
    if (!mark[i]) {
      mark[i] = 1;
      c[k] = i;
      solve(k+1);
      mark[i] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  solve(1);
  cout << res << endl;

  return 0;
}
