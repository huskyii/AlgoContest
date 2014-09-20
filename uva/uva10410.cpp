/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-08-20			*/
/****************************************/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int bfs[1005];
int dfs[1005];
vector<int> t[1005];
size_t s = 0;
size_t e = 0;

int find(int *seq, size_t len, int elem){
    for(size_t i = 0; i < len; i++){
        if(seq[i] == elem){
            return i;
        }
    }
    return -1;
}

int main(void){
    int n;
    while(scanf("%d", &n) == 1){
        getchar();
        for(int i = 1; i <= n; i++){
            t[i].clear();
        }
        for(int i = 0; i < n; i++){
            scanf("%d", bfs+i);
        }
        getchar();
        for(int i = 0; i < n; i++){
            scanf("%d", dfs+i);
        }
        getchar();
        s = 1;
        e = (size_t) n;
        for(int i = 0; i < n; i++){
            printf("%d:", i+1);
            for(vector<int>::iterator j = t[i].begin(); j != t[i].end(); j++){
                printf(" %d", *j);
            }
            printf("\n");
        }
    }
    return 0;
}
