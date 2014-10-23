// 无聊的英语阅读题，WA不止
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct Song {
  int id, r;
  Song(int _id, int _r): id(_id), r(_r) {}
  bool operator<(Song s) const {
    if(r < s.r) return true;
    else if(r > s.r) return false;
    else return id > s.id;
  }
};

int main(void){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  priority_queue<Song> pq;
  int n, t, r;
  cin >> n >> t;
  for(int i = 1; i <= n; ++i) {
    cin >> r;
    pq.push(Song(i, r));
  }
  for(int i = 0; i < t; ++i) {
    Song cur = pq.top();
    cout << cur.id << endl;
    pq.pop();
    vector<Song> tmp;
    while(!pq.empty()) {
      Song ts = pq.top();
      ts.r += cur.r/(n-1);
      if(cur.id <= cur.r%(n-1)) {
        if(ts.id <= cur.r%(n-1)+1)
          ts.r++;
      } else {
        if(ts.id <= cur.r%(n-1))
          ts.r++;
      }
      tmp.push_back(ts);
      pq.pop();
    }
    cur.r = 0;
    pq.push(cur);
    for(size_t j = 0; j < tmp.size(); ++j)
      pq.push(tmp[j]);
  }
  return 0;
}
