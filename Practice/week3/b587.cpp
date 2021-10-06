#include <bits/stdc++.h>
using namespace std;
int dp[32] = {1, 2};
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
  for (int i = 2; i < 31; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2];
    dp[++i] = 2 * dp[i - 1] + dp[i - 2];
  }
  while (cin >> n and n != -1) {
    foo(n);
  }
  return 0;
}