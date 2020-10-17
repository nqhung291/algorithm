#include <bits/stdc++.h>
using namespace std;

const int mxN=1e6;
int n;
int a[mxN];

// void merge(int l, int m, int r) {
//   int temp[r-l+1];
//   int i = l; // first position of first list
//   int j = m+1; // first position of second list
//   for (int k = l; k <= r; k++) {
//     if (i <= m && j <= r) { 
//       if (a[i] < a[j]) { // not scanned all 
//         temp[k] = a[i];
//         i++;
//       } else {
//         temp[k] = a[j];
//         j++;
//       }
//     } else if (i > m) { // left is all scanned
//       temp[k] = a[j];
//       j++;
//     } else { // right is all scanned
//       temp[k] = a[i];
//       i++;
//     }
//   }
//   for (int k = l; k <= r; k++) {
//     a[k] = temp[k];
//   } 
// }

// void merge_sort(int l, int r) {
//   if (l<r) {
//     int m = (l+r)/2;
//     merge_sort(l, m);
//     merge_sort(m+1, r);
//     merge(l, m, r);
//   }
// }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  // merge_sort(0, n-1);
  sort(a, a+n);

  for (int i=0; i<n; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
}
