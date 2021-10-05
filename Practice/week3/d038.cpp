#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void foo() {
  int n;
  while (cin >> n and n != 0) {
    if (n == 1) {
      cout << 1 << "\n";
      continue;
    }
    ll f = 1, s = 2;
    for (int i = 3; i <= n; ++i) {
      ll x = f + s;
      f = s;
      s = x;
    }
    cout << s << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) {
    foo();
  }
  return 0;
}