#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ops;
  multiset<int> ms;
  while (cin >> ops) {
    if (ops == 1) {
      int x;
      cin >> x;
      ms.insert(x);
    } else if (ops == 2) {
      auto it = prev(ms.end());
      cout << *it << "\n";
      ms.erase(it);
    } else {
      auto it = ms.begin();
      cout << *it << "\n";
      ms.erase(it);
    }
  }
  return 0;
}