//題4:https://judge.csie.ncku.edu.tw/problems/8
//劈瓦 DP
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll dp[3333][3333],a[3333],n,m;
ll calc(int now, ll p) {
  if (now >= n || dp[now][p]) return dp[now][p];
  ll dif = p - a[now];
  if (dif > 0) {
    return dp[now][p] = max(calc(now + 1, min(m, p + a[now])), a[now] + calc(now + 1, dif));
  } else {
    return dp[now][p] = max(calc(now + 1, min(m, p + a[now])), p + calc(now + 1, 0));
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << calc(0, 0) << endl;
}