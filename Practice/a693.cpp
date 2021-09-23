# include <bits/stdc++.h>
using namespace std;

void foo(int n,int m){

    vector<int> prefix(n+1);
    
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        prefix[i+1]=prefix[i]+x;
    }

    while(m--){
        int l,r;
        cin >> l >> r;
        cout << prefix[r]-prefix[l-1] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    while(cin >> n >>m)
        foo(n,m);
    return 0;
}