//#define debug
#include <cstdio>
using namespace std;

int main(void){
#ifdef debug
    freopen("uva679.in", "r", stdin);
#endif
    int d, i, kase;
    scanf("%d", &kase);
    while(scanf("%d %d", &d, &i) == 2){
        int k = 1;
        d--;
        while(d--){
            if(i%2){
                k = 2*k;
                i = (i+1)/2;
            }else{
                k = 2*k + 1;
                i = i/2;
            }
        }
        printf("%d\n", k);
    }
    return 0;
}
