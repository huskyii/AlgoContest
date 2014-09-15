/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-09-07			*/
/****************************************/
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long int64;

inline int64 pow(int base, int exp) {
    int64 ans = 1;
    for(int i = 0; i < exp; i++)
        ans *= base;
    return ans;
}

inline int s(int64 x) {
    int ans = 0;
    while(x > 0) {
        ans += x%10;
        x /= 10;
    }
    return ans;
}

int64 ans[100];

int main(void){
    int a, b, c;
    int64 x;
    while(scanf("%d %d %d", &a, &b, &c) != EOF) {
        int cur = 0;
        for(int i = 1; i <= 81; i++) {
            x = b * pow(i, a) + c;
            if(x < 1000000000 && s(x) == i) ans[cur++] = x;
        }

        printf("%d\n", cur);
        for(int i = 0; i < cur; i++) {
            if(i) printf(" ");
            cout << ans[i];
        }
        if(cur) printf("\n");
    }
    return 0;
}
