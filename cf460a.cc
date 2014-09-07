/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-09-07			*/
/****************************************/
#include <cstdio>
using namespace std;

int main(void){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        int ans = 0;
        while(n >= m) {
            int cnt = n/m;
            n -= cnt * m;
            ans += cnt * m;
            n += cnt;
        }
        ans += n;
        printf("%d\n", ans);
    }
    return 0;
}
