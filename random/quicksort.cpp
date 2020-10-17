#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;
int n;
int a[mxN];

int partition(int l, int r) {
  int pivotIndex = r;
  
}

void quicksort(int l, int r) {
  if (l < r) {
    int pivot = partition(l, r);
    if (l < pivot - 1) {
      quicksort(l, pivot - 1);
    } 
    if (r > pivot + 1) {
      quicksort(pivot + 1, r);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  quicksort(0, n-1);
}
