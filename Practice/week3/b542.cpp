#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void foo() {
  int n, q;
  cin >> n >> q;
  vector<ll> arr(n);
  // core dump using hashset find
  // unordered_set<ll> s;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(begin(arr), end(arr));
  for (int i = 0; i < q; ++i) {
    int k;
    cin >> k;
    int l = 0, r = 1;
    while (r < n and arr[r] - arr[l] != k) {
      if (arr[r] - arr[l] > k) {
        ++l;
      } else {
        ++r;
      }
    }
    if (arr[r] - arr[l] == k) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  foo();
  return 0;
}