/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-17        */
/****************************************/
// 坑爹的PE
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 2000 + 5;
char orgin[maxn];

int main(void){
  int n;
  while(scanf("%d", &n) != EOF) {
    getchar();
    for(int i = 0; i < n; i++) scanf("%c\n", orgin+i);
    //orgin[n] = '\0';
    //puts(orgin);

    int l = 0, r = n-1, pos = 0;
    bool flag;
    while(l <= r) {
      for(int i = 0; l+i <= r; ++i) {
        if(orgin[l+i] < orgin[r-i]) { flag = 1; break; }
        if(orgin[l+i] > orgin[r-i]) { flag = 0; break; }
      }
      if(flag) putchar(orgin[l++]);
      else putchar(orgin[r--]);
      if((++pos)%80 == 0) putchar('\n');
    }
    putchar('\n');
  }
  return 0;
}
