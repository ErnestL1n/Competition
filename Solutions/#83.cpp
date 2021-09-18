#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio (false);
    cin.tie (0);
    int n;
    cin >> n;
    vector<array<int,3>> v(n);
    for(auto& x:v)
        cin >> x[0] >> x[1] >> x[2];

    int res=0;

    for(int i=1;i<n;++i){
        int cnt=0;
        for(int j=0;j<3;++j)
            if(v[res][j]<v[i][j])
                ++cnt;
        if(cnt>1)
            res=i;    
    }

    for(int i=0;i<n;++i){
        if(res==i)
            continue;
        int cnt=0;
        for(int j=0;j<3;++j)
            if(v[res][j]>v[i][j])
                ++cnt;
            if(cnt<2){
                cout << -1;
                return 0;
            }
    }

    cout << res+1;

    return 0;
}