//題5:https://judge.csie.ncku.edu.tw/problems/9
//TLE版本
// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

int data[maxN];

int main(){
  int n, m, l, r, ma, type, cnt = 0;
  cin >> n >> m;
  for ( int i = 1 ; i <= n ; i++ )
    cin >> data[i];
  while ( m-- ){
    cin >> type;
    if ( type == 1 )
      cin >> l >> data[l];
    else{
      ma = -1;
      cin >> l >> r;
      for ( int i = l ; i <= r ; i++ )
        ma = max ( ma, data[i] );
      cout << ma << '\n';
    }
  }
}


//標準版
// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005

int seg[maxN << 2];

void update ( int l, int r, int index, int value, int n ){
  if ( l == r )
    seg[n] = value;
  else{
    int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
    if ( index <= mid )
      update ( l, mid, index, value, leftSon );
    else
      update ( mid + 1, r, index, value, rightSon );

    seg[n] = max ( seg[leftSon], seg[rightSon] );
  }
}

int query ( int l, int r, int nowL, int nowR, int n ){
  if ( l <= nowL && nowR <= r )
    return seg[n];
  int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
  if ( r <= mid )
    return query ( l, r, nowL, mid, leftSon );
  if ( mid < l )
    return query ( l, r, mid + 1, nowR, rightSon );
  return max ( query ( l, r, nowL, mid, leftSon ), query ( l, r, mid + 1, nowR, rightSon ) );
}

int main(){
  ios::sync_with_stdio ( false );
  cin.tie ( 0 );
  cout.tie ( 0 );

  int n, m, l, r, value, type;
  cin >> n >> m;
  for ( int i = 1 ; i <= n ; i++ ){
    cin >> value;
    update ( 1, n, i, value, 1 );
  }
  while ( m-- ){
    cin >> type >> l >> r;
    if ( type == 1 )
      update ( 1, n, l, r, 1 );
    else
      cout << query ( l, r, 1, n, 1 ) << '\n';
  }
}