// TODO
/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-09-03			*/
/****************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int s[55], n, goal, sum;
bool v[55];

bool dfs(int now, int idx, int cnt) {
    if(goal * cnt == sum) return true;
    for(int i = idx; i < n; i++) {
        if(v[i] || (i && !v[i-1] && s[i] == s[i-1])) continue;
        if(now + s[i] == goal) {
            v[i] = true;
            if(dfs(0, 0, cnt+1)) return true;
            v[i] = false;
            return false;
        } else if(now + s[i] < goal) {
            v[i] = true;
            if(dfs(now+s[i], idx+1, cnt)) return true;
            v[i] = false;
            if(now == 0) return false;
        }
    }
    return false;
}

bool cmp(int a, int b) {
    return a > b;
}

int main(void) {
    while(scanf("%d", &n) == 1 && n) {
        sum = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", s+i);
            sum += s[i];
        }

        sort(s, s+n, cmp);

        for(goal = s[0]; goal <= sum; goal++) {
            if(sum%goal) continue;
            memset(v, 0, sizeof(v));
            if(dfs(0, 0, 0)) {
                printf("%d\n", goal);
                break;
            }
        }
    }
    return 0;
}
