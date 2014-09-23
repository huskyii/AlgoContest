/*
ID: mail.ji1
PROG: milk3
LANG: C++11
*/
#include <set>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

int A, B, C;
set<int> ans;
// a, b
set< pair<int, int> > state;

void solve(pair<int, int> ab, int c, int d) {
  if(d == 0) return ;
  if(state.find(ab) == state.end())
    state.insert(ab);
  else
    return ;
  if(ab.first == 0) ans.insert(c);
  int a = ab.first, b = ab.second;
  solve(make_pair(max(0,a+b-B), min(B,a+b)), c, d-1);
  solve(make_pair(max(0,a+c-C), b), min(C,a+c), d-1);
  solve(make_pair(a, max(0,b+c-C)), min(C,b+c), d-1);
  solve(make_pair(min(A,b+a), max(0,b+a-A)), c, d-1);
  solve(make_pair(a, min(B,b+c)), max(0,b+c-B), d-1);
  solve(make_pair(min(A,a+c), b), max(0,a+c-A), d-1);
}

int main(void) {
  freopen("milk3.in", "r", stdin);
  freopen("milk3.out", "w", stdout);

  int max_deepth = 100;
  while(scanf("%d %d %d", &A, &B, &C) != EOF) {
    ans.clear();
    state.clear();
    solve(make_pair(0, 0), C, max_deepth);
    int i = 0;
    for(auto elem: ans) {
      if(i++) printf(" ");
      printf("%d", elem);
    }
    printf("\n");
  }

  return 0;
}
