/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-13        */
/****************************************/
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

char s[55];
int len;

inline bool ababa() {
  for(int la = 1; la <= (len-2)/3; la++) {
    if((len-3*la)%2 == 1) continue;
    int lb = (len-3*la)/2;
    if(memcmp(s,s+lb+la, sizeof(char)*la) == 0 &&
       memcmp(s, s+2*la+2*lb, sizeof(char)*la) == 0 &&
       memcmp(s+la, s+2*la+lb, sizeof(char)*lb) == 0) {
      if(la != lb)
          return true;
      else if(memcmp(s, s+la, sizeof(char)*la) != 0)
          return true;
    }
  }
  return false;
}

inline bool ababcab() {
  for(int ld = 2; ld <= (len-1)/3; ld++) {
    int lc = len-3*ld;
    if(memcmp(s, s+ld, sizeof(char)*ld) == 0 &&
       memcmp(s, s+2*ld+lc, sizeof(char)*ld) == 0)
      for(int la = 1; la < ld; la++) {
        int lb = ld - la;
        if(la == lb && memcmp(s, s+la, sizeof(char)*la) == 0) continue;
        if(la == lc && memcmp(s, s+2*ld, sizeof(char)*lc) == 0) continue;
        if(lb == lc && memcmp(s+la, s+2*ld, sizeof(char)*lc) == 0) continue;
        return true;
      }
  }
  return false;
}

int main(void){
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%s", s);

    int cur = 0;
    for(size_t i = 0; i < strlen(s); ++i)
      if(isalpha(s[i])) s[cur++] = s[i];
    s[cur] = '\0';

    len = strlen(s);
    if(ababa() || ababcab()) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
