//題7:https://judge.csie.ncku.edu.tw/problems/11
#include <bits/stdc++.h>
using namespace std;

long long tennn(long long a) {
  int c = 0;
  while(a >= 10) a /= 10, c++;
  long long b = 1;
  for(int i = 0; i < c+1; i++) b *= 10;
  return b;
}

int main() {
  long long B[3];
  long long A[6] = {};
  for(int i = 0; i < 3; i++) cin >> B[i];
  int c = 0;
  for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) for(int k = 0; k < 3; k++) if(i != j && i != k && j != k) {
    A[c++] = B[i] + B[j]*tennn(B[i]) + B[k] * tennn(B[i]) * tennn(B[j]);
  }
  long long maxi  =  0;
  for(int i = 0; i < c; i++) maxi = maxi > A[i]? maxi: A[i];
  cout << maxi << endl;
  return 0;
}

/* python 版本
a, b, c = input().strip().split(' ')
s = [a+b+c,a+c+b,b+a+c,b+c+a,c+a+b,c+b+a]
s = map(int, s)
print(max(s))
*/