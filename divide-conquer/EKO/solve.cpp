/*
Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.
Mirko's machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).
Mirko is ecologically minded, so he doesn't want to cut off more wood than necessary. That's why he wants to set his sawblade as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.
Input
The first line of input contains two space-separated positive integers, N (the number of trees, 1≤N≤1000000) and M (Mirko's required wood amount, 1≤M≤2000000000).
The second line of input contains N space-separated positive integers less than 1 000 000 000, the heights of each tree (in metres). The sum of all heights will exceed M, thus Mirko will always be able to obtain the required amount of wood.
Output
The first and only line of output must contain the required height setting.

*/
#include <bits/stdc++.h>
using namespace std;

unsigned long long N, M, t[1000001]; 
unsigned long long tmax = -1;

unsigned long long amount(unsigned long long h) {
  unsigned long long sum = 0;
  for (unsigned long long i = 1; i <= N; i++) {
    if (t[i] > h) {
      sum += (t[i] - h);
    }
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (unsigned long long i=1;i<= N;i++) {
    cin >> t[i];
    tmax = max(tmax, t[i]);
  }

  unsigned long long lo = 0, hi = tmax;
  while (lo < hi - 1) {
    unsigned long long m = (lo + hi)/2;
    unsigned long long temp = amount(m);
    if (temp == M) {
      cout << m << endl;
      return 0;
    } else if (temp > M) {
      lo = m;
    } else {
      hi = m;
    }
  }
  if (amount(lo) >= M) {
    cout << lo << endl;
    return 0;
  }
  return 0;
}
