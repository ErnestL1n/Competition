//題1:https://judge.csie.ncku.edu.tw/problems/4 
//模擬題
#include<bits/stdc++.h>
using namespace std;
int main(){
	int odd=0,even=0;
    string str;
	cin >> str;
	for(int i=0;i<12;++i){
		if(i%2==1)//index from 0=> even is 1 3 5 7 9
			even+=str[i];
		else
			odd+=str[i];
	}
	cout << 9-(odd+3*even-1)%10 << '\n';
}