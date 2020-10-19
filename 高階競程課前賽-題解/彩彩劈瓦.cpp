// #include <iostream>
// #include <algorithm>
// using namespace std;
// //using ll=long long int;
// int const maxn=3e3+10,maxL=3e3+10;
// int const INF=0xffffffff;
// int dp[3333][3333],a[3333],n,L;

// int main(){
//   cout<< "Enter n and L respectively:";
//   scanf("%d %d",&n,&L);
//   cout<< "Enter a[i] one by one:";
//   for(int i=0;i<n;++i)
//   scanf("%d",&a[i]);

//   for(int i=0;i<n;++i){
//     for(int p=0;p<=L;++p){
//     dp[i][p]=-INF;
//     dp[0][min(L,a[0])]=0;
//     }
//   }

//   for(int i=1;i<n;++i){
//     for(int p=L;p>=0;--p){
//       int x=min(a[i],p);
//       if(p-x>=0){
//         dp[i][p-x]=max(dp[i][p-x],dp[i-1][p]+x);
//       }
//       if(p+a[i]<=L){
//         dp[i][p+a[i]]=max(dp[i][p+a[i]],dp[i-1][p]);
//       }
//       else{
//         dp[i][L]=max(dp[i][L],dp[i-1][p]);
//       }
//     }
//   }

//   int ans=0;
//   for(int p=0;p<=L;++p){
//     ans=max(ans,dp[n-1][p]);
//   }

//   printf("%d \n",ans);

//   return 0;
// }

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