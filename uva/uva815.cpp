// #define LOCAL
#include <cstdio>
#include <algorithm>
using namespace std;

int e[905];

int main(void){
#ifdef LOCAL
    freopen("uva815.in", "r", stdin);
    freopen("uva815.out", "w", stdout);
#endif
    int kase = 0;
    int m, n, total, water;
    float level, cover;
    bool flag;
    while(scanf("%d %d", &m, &n) && m){
        flag = false;
        total = m*n;
        for(int i = 0; i < total; ++i)
            scanf("%d", &e[i]);
        scanf("%d", &water);
        sort(e, e+total);
        for(int i = 1; i < total; ++i){
            if((e[i]-e[i-1])*i*100 < water)
                water -= (e[i] - e[i-1])*i*100;
            else{
                flag = true;
                level = e[i-1] + water/(i*100.0);
                cover = float(i)/total;
                cover *= 100;
                break;
            }
        }
        if(!flag){
            cover = 100.0;
            level = e[total-1] + water/(total*100.0);
        }
        printf("Region %d\n", ++kase);
        printf("Water level is %.2f meters.\n", level);
        printf("%.2f percent of the region is under water.\n\n", cover);
    }

    return 0;
}
