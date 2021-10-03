#include <bits/stdc++.h>
using namespace std;

void foo(int n, int m) {}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  map<string, int> m;
  int n;
  while (cin >> n) {
    m.clear();
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
      string x;
      cin >> x;
      if (m.find(x) == m.end()) {
        m[x] = cnt;
        cout << "New! " << cnt << "\n";
        ++cnt;
      } else {
        cout << "Old! " << m[x] << "\n";
      }
    }
  }
  return 0;
}