#include <stdio.h>
#include <map>
#include <set>
using namespace std;

int pop(map<int, multiset<int> > &a, map<int, multiset<int> > &b, int key){
  int res = a[key].size();
  for(multiset<int>::iterator it = a[key].begin(); it != a[key].end(); it++){
    b[*it].erase(key);
  }
  a[key].clear();
  return res;
}

int main(void){
  int n, m;
  int x, y;
  int c, d;
  map<int, multiset<int> > xx;
  map<int, multiset<int> > yy;
  while(1){
    scanf("%d %d", &n, &m);
    if(n == 0 && m == 0)
      break;
    for(int i = 0; i < n; ++i){
      scanf("%d %d", &x, &y);
      xx[x].insert(y);
      yy[y].insert(x);
    }
    for(int i = 0; i < m; ++i){
      scanf("%d %d", &c, &d);
      if(c == 0){
        printf("%d\n", pop(xx,yy,d));
      }else{
        printf("%d\n", pop(yy,xx,d));
      }
    }
    printf("\n");
  }
  return 0;
}
