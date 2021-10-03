#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, res = 0;
  cin >> n;
  vector<int> s(n + 1);
  // i is used to compare with n
  // while s[i] is used to record score
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    if (i + x > n)
      res = max(res, s[i] + x);
    else
      s[i + x] = max(s[i + x], s[i] + x);
  }
  cout << res << "\n";
  return 0;
}
