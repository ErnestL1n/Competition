#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long
ll dp[3333][3333],a[3333],n,L;

ll calc(ll now,ll p){
  if(now>=n||dp[now][p])
  return dp[now][p];
  //since a[] begins from a[0]
  ll dif=p-a[now];
  if(dif>0)
  return dp[now][p]=max(calc(now+1,p+min(L,p+a[now])),a[now]+calc(now+1,dif));
  else
  return dp[now][p]=max(calc(now+1,p+min(L,p+a[now])),p+calc(now+1,0));
}


int main() {
  cin >> n >> L;
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << calc(0, 0) << endl;
}