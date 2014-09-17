/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-17        */
/****************************************/
#include <cstdio>
#include <utility>
using namespace std;

const int maxn = 300 + 5;
pair<int, int> coor[maxn*maxn];

int main(void){
  int n, m, k;
  while(scanf("%d %d %d", &n, &m, &k) != EOF) {
    int pos = 0;
    for(int i = 1; i <= n; ++i) {
      if(i%2) {
        for(int j = 1; j <= m; ++j) {
          coor[pos].first = i;
          coor[pos++].second = j;
        }
      } else {
        for(int j = m; j > 0; --j) {
          coor[pos].first = i;
          coor[pos++].second = j;
        }
      }
    }

    for(int i = 0; i < k-1; ++i) {
      printf("2 %d %d %d %d\n", coor[i*2].first, coor[i*2].second, coor[i*2+1].first, coor[i*2+1].second);
    }
    printf("%d", n*m - 2*(k-1));
    for(int i = 2*(k-1); i < n*m; ++i) printf(" %d %d", coor[i].first, coor[i].second);
    printf("\n");
  }
  return 0;
}
