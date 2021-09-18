# include <bits/stdc++.h>
using namespace std;

int main(){
    char a,b,c;
    int cnt=0;
    cin >> a >> b >> c;
    if(a=='+')
        ++cnt;
    if(b=='+')
        ++cnt;
    if(c=='+')
        ++cnt;
    if(cnt==1 or cnt==3)
        cout << "yes";
    else
        cout << "no";
    return 0;
}