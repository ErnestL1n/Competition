//題3:https://judge.csie.ncku.edu.tw/problems/7
#include <iostream>
using namespace std;

int a[500050];
int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  int i, j;
  for (i = 1; i <= n; i++) {
    cin >> j;
    a[n - j + 1] = i;
  }

  for (i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}