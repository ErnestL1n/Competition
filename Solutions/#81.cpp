# include <bits/stdc++.h>
using namespace std;

int main(){
    int n,res=0;
    string s;
    cin >> n;
    cin >> s;
    for(const auto& c:s){
        if(c=='+')
            ++res;
        if(c=='-')
            if(res>0)
                --res;
    }
    cout << res;
}