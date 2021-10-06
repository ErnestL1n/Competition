#include <bits/stdc++.h>
using namespace std;
vector<int> dp(32);
typedef long long ll;
void foo(int n) {
  if (n % 2 == 0) {
    cout << dp[n] << "\n";
  } else {
    cout << 0 << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  dp[0] = 1;
  dp[2] = 3;
  for (int i = 4; i < 31; i += 2) {
    dp[i] = 4 * dp[i - 2] - dp[i - 4];
  }
  while (cin >> n and n != -1) {
    foo(n);
  }
  return 0;
}