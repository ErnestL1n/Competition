//題4:https://judge.csie.ncku.edu.tw/problems/8
//劈瓦 DP

//version 1:
#include<cstdio>
#include<algorithm>
using namespace std;

int const maxn = 3e3 + 10, maxl = 3e3 + 10;
int const INF = 0x3f3f3f3f;

int n, L, a[maxn], dp[maxn][maxl];

int main()
{
  scanf("%d%d", &n, &L);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  for(int i = 0; i < n; i++)
    for(int P = 0; P <= L; P++) dp[i][P] = -INF;
  dp[0][min(L, a[0])] = 0;

  for(int i = 1; i < n; i++)
    for(int P = L; P >= 0; P--) {
      int g = min(P, a[i]);
      if(P-g    >= 0) dp[i][P-g]    = max(dp[i][P-g], dp[i-1][P] + g);
      if(P+a[i] <= L) dp[i][P+a[i]] = max(dp[i][P+a[i]], dp[i-1][P]);
      else dp[i][L] = max(dp[i][L], dp[i-1][P]);
    }

  int ans = 0;
  for(int P = 0; P <= L; P++) ans = max(ans, dp[n-1][P]);

  printf("%d\n", ans);

  return 0;
}















//version 2:
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
  // << calc(0,0)應改為calc<m,n>
  cout << calc(0, 0) << endl;
}