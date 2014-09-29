/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-09-29        */
/****************************************/
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

inline bool lt(const string &s1, const string &s2) {
  if(s1.compare(s2) < 0) return true;
    else return false;
}

const int MAXN = 100000 + 5;
int n, p[MAXN];
string f[MAXN], l[MAXN];

int main(void){
  ios_base::sync_with_stdio(false);

  cin >> n;
  for(int i = 1; i <= n; ++i)
    cin >> f[i] >> l[i];
  for(int i = 0; i < n; ++i)
    cin >> p[i];

  bool flag = true;
  string str = lt(f[p[0]], l[p[0]])? f[p[0]]: l[p[0]];
  for(int i = 1; i < n; ++i) {
    if(lt(str, f[p[i]]) && lt(str, l[p[i]]))
      str = lt(f[p[i]], l[p[i]])? f[p[i]]: l[p[i]];
    else if(lt(str, f[p[i]])) str = f[p[i]];
    else if(lt(str, l[p[i]])) str = l[p[i]];
    else { flag = false; break; }
  }
  if(flag) printf("YES\n");
  else printf("NO\n");

  return 0;
}
