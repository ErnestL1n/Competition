#include<iostream>
using namespace std;
int main(){
    int odd=0,even=0;
    string str;
    cin >> str;
    for(int i=0;i<12;++i){
        if(i%2==0){
            odd+=str[i]-'0';
        }
        else
        {
            even+=str[i]-'0';
        }
    }
    cout << 9-(odd+3*even-1)%10 <<"\n";
    return 0;
}

