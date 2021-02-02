#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=3e3+10,maxl=3e3+10;
const int inf=0x7fffffff;

int a[maxn],dp[maxn][maxn],day,P;


int main(){ 
  cout << "Enter n and L respectively:" ;
  scanf("%d %d",&day,&P);
  cout << "Enter a[i] one by one:";
  for(int i=0;i<day;++i)
    scanf("%d",&a[i]);

  for(int i=0;i<day;++i)
    for(int j=0;j<=P;++j)
      dp[i][j]=-inf;
  
  //first day
  dp[0][min(P,a[0])]=0;

  for(int i=1;i<day;++i)
    for(int p=P;p>=0;--p){
      auto g=min(p,a[i]);
      //do it
      if(p-g>=0)  //tomorrow
        dp[i][p-g]=max(dp[i-1][p]+g,dp[i][p-g]);
      //don't do
      if(p+a[i]<=P)  //tomorrow
        dp[i][p+a[i]]=max(dp[i-1][p],dp[i][p+a[i]]);
      else
        dp[i][P]=max(dp[i-1][p],dp[i][P]);
    }

    int res=0;
    for(int i=0;i<=P;++i)
      res=max(res,dp[day-1][i]);

    cout << "answer is :" << res;

  return 0;
}