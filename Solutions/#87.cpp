# include <bits/stdc++.h>
using namespace std;

int foo(){
    int N,a,b;
    string s;
    cin >> N >> a >> b;
    cin >> s;
    if(b<0){
        int cnt=1;
        for(int i=1;i<s.size();++i)
            if(s[i]!=s[i-1])
                ++cnt;
        return a*N+(cnt/2+1)*b;
    }else{
        return a*N+b*N;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--)
        cout << foo() << "\n";
    return 0;
}