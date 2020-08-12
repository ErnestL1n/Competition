//題6:https://judge.csie.ncku.edu.tw/problems/10
//單源最短路裸題
//標程為 SPFA，不過因為用了怪怪的優化方法，所以下面放的 code 是 Dijkstra
//想要 SPFA 做法的可以來問（？
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005

vector < pair < int, long long > > edges[maxN];
long long dis[maxN];

int main(){
  ios::sync_with_stdio ( false );
  cin.tie ( 0 );
  cout.tie ( 0 );

  int n, m, u, v, w, now;
  long long d;
  cin >> n >> m;
  while ( m-- ){
    cin >> u >> v >> w;
    edges[u].emplace_back ( v, w );
    edges[v].emplace_back ( u, w );
  }
  priority_queue < pair < long long, int >, vector < pair < long long, int > >, greater < pair < long long, int > > > pq;
  memset ( dis, 0x3f3f3f3f3f3f3f, sizeof ( dis ) );
  dis[0] = 0;
  pq.push ( make_pair ( 0, 0 ) );
  while ( !pq.empty() ){
    now = pq.top().second, d = pq.top().first;
    pq.pop();
    if ( dis[now] < d )
      continue;
    for ( auto i: edges[now] ){
      if ( dis[i.first] > d + i.second ){
        dis[i.first] = d + i.second;
        pq.push ( make_pair ( dis[i.first], i.first ) );
      }
    }
  }

  for ( int i = 0 ; i < n ; i++ )
    cout << dis[i] << ' ';
  cout << '\n';
}