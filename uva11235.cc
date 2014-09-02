/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-09-01			*/
/****************************************/
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
const int logmaxn = 20;
int num[maxn], left[maxn], right[maxn], c[maxn], a[maxn];

int m[maxn][logmaxn];

void st_init(int n) {
    for(int i = 0; i < n; i++) {
        m[i][0] = c[i];
    }

    for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 0; i+(1<<j)-1 < n; i++) {
            m[i][j] = max(m[i][j-1], m[i+(1<<(j-1))][j-1]);
        }
    }
}

int st_query(int l, int r) {
    int k = 0;
    while((1 << (k+1)) <= r-l+1) k++;
    return max(m[l][k], m[r-(1 << k)+1][k]);
}

int main(void){
    int n, q;
    while(scanf("%d %d", &n, &q) == 2) {
        for(int i = 0; i < n; i++)
            scanf("%d", a+i);

        int start = 0;
        int cur = 0;
        for(int i = 0; i < n-1; i++) {
            if(a[i] < a[i+1]) {
                c[cur] = i+1 - start;
                for(int j = start; j < i+1; j++) {
                    left[j] = start;
                    right[j] = i;
                    num[j] = cur;
                }
                start = i+1;
                cur++;
            }
        }
        if(a[n-2] == a[n-1]) {
            c[cur] = n - start;
            for(int j = start; j < n; j++) {
                left[j] = start;
                right[j] = n-1;
                num[j] = cur;
            }
        } else {
            c[cur] = 1;
            left[n-1] = n-1;
            right[n-1] = n-1;
            num[n-1] = cur;
        }
        /*
         *for(int i = 0; i <= cur; i++)
         *    printf("%d ", c[i]);
         *printf("\n");
         *for(int i = 0; i < n; i++)
         *    printf("%d ", num[i]);
         *printf("\n");
         *for(int i = 0; i < n; i++)
         *    printf("%d ", left[i]);
         *printf("\n");
         *for(int i = 0; i < n; i++)
         *    printf("%d ", right[i]);
         *printf("\n");
         */

        st_init(n);
        int l, r, ans;
        for(int i = 0; i < q; i++) {
            scanf("%d %d", &l, &r);
            l--; r--;
            if(num[l] == num[r])
                ans = r-l+1;
            else {
                ans = max(r-left[r]+1, right[l]-l+1);
                if(num[r] > num[l]+1)
                    ans = max(ans, st_query(num[l]+1, num[r]-1));
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
