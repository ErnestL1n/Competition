#include <bits/stdc++.h>
using namespace std;

// brute force => TLE
// int data[maxn<<2];
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int n,m,type,l,r;
//     cin >> n >>m;
//     for(int i=1;i<=n;++i)
//         cin >> data[i];

//     while(m--){
//         cin >> type;
//         if(type==1)
//             cin >> l >> data[l];
//         else{
//             int tmp=INT_MIN;
//             cin >>l >>r;
//             for(int i=l;i<=r;++i)
//                 tmp=max(tmp,data[i]);
//             cout << tmp <<"\n";
//         }
//     }
//     return 0;
// }

int* segTree;
void update(int idx, int val, int l, int r, int segidx) {
  if (l == r)
    segTree[segidx] = val;
  else {
    int mid = (l + r) / 2, leftson = segidx * 2, rightson = segidx * 2 + 1;
    if (idx <= mid)
      update(idx, val, l, mid, leftson);
    else
      update(idx, val, mid + 1, r, rightson);
    segTree[segidx] = max(segTree[leftson], segTree[rightson]);
  }
}

int query(int left, int right, int l, int r, int segidx) {
  if (left <= l and right >= r) return segTree[segidx];
  int mid = (l + r) / 2, leftson = segidx * 2, rightson = segidx * 2 + 1;
  if (right <= mid) return query(left, right, l, mid, leftson);
  if (left > mid) return query(left, right, mid + 1, r, rightson);
  return max(query(left, right, l, mid, leftson),
             query(left, right, mid + 1, r, rightson));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, l, r, type, val;
  cin >> n >> m;
  segTree = (int*)calloc(n * 4, sizeof(int));
  for (int i = 1; i <= n; ++i) {
    cin >> val;
    update(i, val, 1, n, 1);
  }
  while (m--) {
    cin >> type >> l >> r;
    if (type == 1)
      update(l, r, 1, n, 1);
    else
      cout << query(l, r, 1, n, 1) << "\n";
  }
  return 0;
}