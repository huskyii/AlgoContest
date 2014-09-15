/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-09-04			*/
/****************************************/
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

inline int lowbit(int x) {
    return (x&(-x));
}

const int maxn = 32010;

int f[maxn];

inline void add(int idx) {
    for(int i = idx; i <= maxn; i += lowbit(i))
        f[i]++;
}

inline int sum(int idx) {
    int s = 0;
    for(int i = idx; i > 0; i -= lowbit(i))
        s += f[i];
    return s;
}

int cnt[15000];

int main(void){
    int n;
    scanf("%d", &n);
    int x, y;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        cnt[sum(++x)]++;
        add(x);
    }
    for(int i = 0; i < n; i++)
        printf("%d\n", cnt[i]);
    return 0;
}
