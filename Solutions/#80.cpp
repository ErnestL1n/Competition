# include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> cnt(101);
    int a;
    for(int i=0;i<n;++i){
        cin >> a;
        ++cnt[a];
    }
    for(int i=1;i<101;++i)
        cout << cnt[i] << " ";
    return 0;
}