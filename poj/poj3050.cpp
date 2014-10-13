/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-10-14        */
/****************************************/
#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int g[5][5];
set< vector<int> > s;

void dfs(int i, int j, int deepth, vector<int> path) {
  path.push_back(g[i][j]);
  if(deepth == 5) { s.insert(path); return ; }

  if(i+1 < 5) dfs(i+1, j, deepth+1, path);
  if(j+1 < 5) dfs(i, j+1, deepth+1, path);
  if(i-1 >= 0) dfs(i-1, j, deepth+1, path);
  if(j-1 >= 0) dfs(i, j-1, deepth+1, path);
}

int main(void){
  for(int i = 0; i < 5; ++i)
    for(int j = 0; j < 5; ++j)
      scanf("%d", &g[i][j]);

  for(int i = 0; i < 5; ++i)
    for(int j = 0; j < 5; ++j) {
      vector<int> path;
      dfs(i, j, 0, path);
    }

  cout << s.size() << endl;

  return 0;
}
