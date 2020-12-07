#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=1e5+20;

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

int seg[maxn<<2];


void update(int index,int val,int l,int r,int n){
    if(l==r)
        seg[n]=val;
    else{
        int mid=(l+r)>>1,leftChild=n<<1,rightChild=leftChild|1; //or rightChild=leftChild+1
        if(index<=mid)
            update(index,val,l,mid,leftChild);
        else 
            update(index,val,mid+1,r,rightChild);
        seg[n]=max(seg[leftChild],seg[rightChild]);
    }
}

int query(int currL,int currR,int l,int r,int n){
    if(currL<=l&&r<=currR)
        return seg[n];
    int mid=(l+r)>>1,leftChild=n<<1,rightChild=leftChild|1;
    // since mid=(l+r)/2  => break range and satisfy if statement will be mid<l
    // since if r=l+1 => (r+l)>>1 =l not r
    if(mid<currL)
        return query(currL,currR,mid+1,r,rightChild);
    if(mid>=currR)
        return query(currL,currR,l,mid,leftChild);
    return max(query(currL,currR,mid+1,r,rightChild),query(currL,currR,l,mid,leftChild));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,l,r,type,val;
    cin >> n >>m;
    for(int i=1;i<=n;++i){
        cin >>val;
        update(i,val,1,n,1);
    }
    while(m--){
        cin >> type >> l >>r;
        if(type==1)
            update(l,r,1,n,1);
        else 
            cout << query(l,r,1,n,1) <<"\n";
    }
    return 0;
}