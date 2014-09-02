/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-09-02			*/
/****************************************/
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int64;

int main(void){
    int T, n, s1, v1, s2, v2;
    int kase = 0;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d %d %d", &n, &s1, &v1, &s2, &v2);
        // make sure s1 < s2
        if(s1 > s2) {
            swap(s1, s2);
            swap(v1, v2);
        }
        int64 ans = 0;
        if(n/s2 >= 65525) {
            for(int64 i = 0; i <= s1; i++) {
                ans = max(ans, i*v2 + (n-s2*i)/s1*v1);
            }
            for(int64 i = 0; i <= s2; i++) {
                ans = max(ans, i*v1 + (n-s1*i)/s2*v2);
            }
        } else {
            for(int64 i = 0; i*s2 <= n; i++) {
                ans = max(ans, i*v2 + (n-i*s2)/s1*v1);
            }
        }
        printf("Case #%d: %lld\n", ++kase, ans);
    }
    return 0;
}
