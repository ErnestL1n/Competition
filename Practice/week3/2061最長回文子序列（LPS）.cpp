#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 10001;
void foo() {
  string s;
  cin >> s;
  int n = s.size(), start;
  // avoid TLE when n>=200000
  if (n >= 10000) {
    int cnt[10] = {};
    for (int i = 0; i < n; ++i) {
      ++cnt[s[i] - '0'];
    }
    for (int i = 0; i < 10; ++i) {
      if (cnt[i] >= 1000) {
        for (int j = 0; j < 1000; ++j) {
          cout << (char)('0' + i);
        }
        cout << "\n";
        break;
      }
    }
    return;
  }
  string revs = s;
  reverse(revs.begin(), revs.end());
  int** dp = (int**)calloc(n + 1, sizeof(int*));
  for (int i = 0; i <= n; ++i) {
    dp[i] = (int*)calloc(n + 1, sizeof(int));
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (dp[i][j] >= 1000) break;
      if (i == 0 or j == 0) {
        dp[i][j] = 0;
        continue;
      }
      if (s[i - 1] == revs[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  // print string
  string res = "";
  int i = n, j = n;
  while (i > 0 and j > 0) {
    if (s[i - 1] == revs[j - 1]) {
      res += s[i - 1];
      --i;
      --j;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      --i;
    } else {
      --j;
    }
  }
  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  foo();
  return 0;
}