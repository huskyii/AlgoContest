/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-08-24			*/
/****************************************/
#include <cstdio>
#include <set>
using namespace std;

int main(void){
    int n, kase = 0;
    int a, b;
    set<int> used;
    while(scanf("%d", &n) && n){
        if(kase++){
            printf("\n");
        }
        int cnt = 0;
        for(int i = 1234; i <= 98745; i++){
            b = i * n;
            if(b/100000){
                continue;
            }
            bool flag = true;
            used.clear();
            a = i;
            for(int j = 0; j < 5; j++){
                if(used.find(a%10) == used.end()){
                    used.insert(a%10);
                    a /= 10;
                }else{
                    flag = false;
                    break;
                }
            }
            if(!flag){
                continue;
            }
            for(int j = 0; j < 5; j++){
                if(used.find(b%10) == used.end()){
                    used.insert(b%10);
                    b /= 10;
                }else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                printf("%05d / %05d = %d\n", i*n, i, n);
                cnt++;
            }
        }
        if(!cnt){
            printf("There are no solutions for %d.\n", n);
        }
    }
    return 0;
}
