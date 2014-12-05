// 非常容易TLE Orz
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int INF = 1e8;
vector<int> G[MAXN];
int d[MAXN][MAXN];
int n, m;
bool v[MAXN];

void bfs(int s) {
  memset(v, 0, sizeof(v));
  queue<int> q;
  q.push(s); v[s] = true;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(size_t i = 0; i < G[u].size(); ++i) {
      int x = G[u][i];
      if(!v[x]) {
        d[s][x] = min(d[s][x], d[s][u]+1);
        q.push(x);
        v[x] = 1;
      }
    }
  }
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  while(cin >> n && n) {
    string x, y;
    map<string, int> t;
    for(int i = 0; i < n; ++i) {
      cin >> x;
      t[x] = i;
    }
    for(int i = 0; i < n; ++i) {
      fill(d[i], d[i]+n, INF);
      d[i][i] = 0;
      G[i].clear();
    }
    cin >> m;
    for(int i = 0; i < m; ++i) {
      cin >> x >> y;
      G[t[x]].push_back(t[y]);
      G[t[y]].push_back(t[x]);
    }
    for(int i = 0; i < n; ++i)
      bfs(i);
    int ans = 0;
    for(int i = 0; i < n; ++i)
      for(int j = i+1; j < n; ++j)
        ans = max(ans, d[i][j]);
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
  }
  return 0;
}
