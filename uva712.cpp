#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

char t[(2 << 7) + 1];

int main(void){
    int order[7];
    char vva[8];
    int n;
    int no = 0;
    while(scanf("%d", &n) && n){
        printf("S-Tree #%d:\n", ++no);
        getchar();
        int kase;
        for(int i = 0; i < n; i++){
            scanf("x%d ", order + i);
        }
        scanf("%s", t);
        scanf("%d", &kase);
        for(int i = 0; i < kase; i++){
            int ans = 1;
            scanf("%s", vva);
            for(int j = 0; j < n; j++){
                if(vva[order[j]-1] == '0'){
                    ans *= 2;
                }else if(vva[order[j]-1] == '1'){
                    ans *= 2;
                    ans++;
                }
            }
            //cout << ans << endl;
            ans = ans - pow(2,n);
            //cout << ans << endl;
            printf("%c", t[ans]);
        }
        printf("\n\n");
    }
    return 0;
}
