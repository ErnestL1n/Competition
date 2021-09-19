# include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;++i){
        int n,m;
        cin >> n >> m;
        vector<vector<int>> mat(n,vector<int>(m));
        for(auto& a:mat)
            for(auto& b:a)
                cin >> b;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j){
                int cnt=4;
                if(i==0 or i==n-1)
                    --cnt;
                if(j==0 or j==m-1)
                    --cnt;
                if(mat[i][j]>cnt){
                    cout << "NO" << "\n";
                    return 0;
                }else{
                    mat[i][j]=cnt;
                }
            }
        cout << "Yes" << "\n";
        for(auto& a:mat){
            for(auto& b:a)
                cout << b <<" ";
            cout << "\n";
        }
    }
    return 0;
}