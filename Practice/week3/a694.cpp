# include <bits/stdc++.h>
using namespace std;

void foo(int n,int m){

    vector<vector<int>> dp(n+1,vector<int>(n+1));

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int x;
            cin >> x;
            dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]-dp[i][j]+x;
        }
    }

    while(m--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    while(cin>>n>>m)
        foo(n,m);
    return 0;
}