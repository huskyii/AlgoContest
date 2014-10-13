/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*         created on 2014-10-13        */
/****************************************/
#include <vector>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3fffffff;
int digit[10], cnt;

inline int vec2int(const vector<int> &v) {
  if(v[0] == 0) return INF;
  int ans = 0;
  for(size_t i = 0; i < v.size(); ++i)
    ans = ans * 10 + v[i];
  return ans;
}

int main(void){
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  getchar();
  while(T--) {
    string s;
    getline(cin, s);
    stringstream ins(s);
    cnt = 0;
    while(ins >> digit[cnt++]) {}
    --cnt;

    int mindiff = INF;
    do {
      if(cnt == 2) { mindiff = digit[1] - digit[0]; break; }
      vector<int> v1(digit, digit+(cnt/2)), v2(digit+(cnt/2), digit+cnt);
      int val1 = vec2int(v1), val2 = vec2int(v2);
      if(val1 != INF && val2 != INF)
        mindiff = min(mindiff, abs(val1-val2));
    } while(next_permutation(digit, digit+cnt));
    cout << mindiff << endl;
  }
  return 0;
}
