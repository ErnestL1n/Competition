#include <bits/stdc++.h>
using namespace std;

void foo(int n, int m) {}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  set<string> s;
  int n, q;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    s.insert(x);
  }
  cin >> q;
  for (int i = 0; i < q; ++i) {
    string x;
    cin >> x;
    if (s.find(x) == s.end()) {
      s.insert(x);
      cout << "no"
           << "\n";
    } else {
      cout << "yes"
           << "\n";
    }
  }
  return 0;
}