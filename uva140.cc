/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-08-25			*/
/****************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10;
int id[256];
char letter[MAXN];

int main(void){
    char input[1000];
    while(scanf("%s", input) == 1 && input[0] != '#'){
        int cnt = 0;
        for(char c = 'A'; c <= 'Z'; c++){
            if(strchr(input, c) != NULL){
               id[int(c)] = cnt++;
               letter[id[int(c)]] = c;
            }
        }

        int len = strlen(input), p = 0, q = 0;
        vector<int> u, v;
        for(;;){
            while(p < len && input[p] != ':') p++;
            if(p == len) break;
            while(q < len && input[q] != ';') q++;
            for(int i = p+1; i < q; i++){
                u.push_back(id[(int)input[p-1]]);
                v.push_back(id[(int)input[i]]);
            }
            p++; q++;
        }

        /*
         *int offset = 0;
         *vector<int> u, v;
         *char a, b;
         *while(sscanf(input+offset, "%c:", &a) == 1){
         *    offset += 2;
         *    while(sscanf(input+offset, "%c", &b) == 1 && b != ';'){
         *        offset++;
         *        u.push_back(id[(int)a]);
         *        v.push_back(id[(int)b]);
         *    }
         *    offset++;
         *}
         */

        int P[MAXN], bestP[MAXN], pos[MAXN], ans = cnt;
        for(int i = 0; i < cnt; i ++)
            P[i] = i;
        do{
            int bandwidth = 0;
            for(int i = 0; i < cnt; i++)
                pos[P[i]] = i;
            for(size_t i = 0; i < u.size(); i++)
                bandwidth = max(bandwidth, abs(pos[u[i]] - pos[v[i]]));
            if(bandwidth < ans){
                ans = bandwidth;
                memcpy(bestP, P, sizeof(P));
            }
        }while(next_permutation(P, P+cnt));
        for(int i = 0; i < cnt; i++)
            printf("%c ", letter[bestP[i]]);
        printf("-> %d\n", ans);
    }
    return 0;
}
