// #define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s1[101],s2[101];

int cnt1[26],cnt2[26];

int main(void){
#ifdef LOCAL
    freopen("uva1339.in", "r", stdin);
    freopen("uva1339.out", "w", stdout);
#endif
    int len;
    while(scanf("%s", s1) != EOF){
        scanf("%s", s2);
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        len = strlen(s1);
        for(int i = 0; i < len; ++i){
            cnt1[s1[i] - 'A']++;
            cnt2[s2[i] - 'A']++;
        }
        sort(cnt1, cnt1+26);
        sort(cnt2, cnt2+26);
        if(memcmp(cnt1, cnt2, sizeof(cnt1)))
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
