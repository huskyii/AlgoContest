/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-09-04			*/
/****************************************/
#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;

const int charset_size = 2, maxn = 100000;
const char base = '0';

inline int id(const char *p) {
    return *p - base;
}

struct Trie {
    // child[i][j] 是第i個節點的第j個子節點的位置
    // 因此可以開出一個 value 數組來存放節點附加信息
    int tot, root, child[maxn][charset_size];
    int val[maxn];

    Trie() {
        memset(child[1], 0, sizeof(child[1]));
        val[1] = 0;
        root = tot = 1;
    }

    void insert(const char *s, int v) {
        int *cur = &root;
        for(const char *p = s; *p; p++) {
            cur = &child[*cur][id(p)];
            if(*cur == 0) {
                *cur = ++tot;
                memset(child[tot], 0, sizeof(child[tot]));
                val[tot] = 0;
            }
        }
        val[tot] = v;
    }

    bool query(const char *s) {
        int cur = root;
        for(const char *p = s; *p && cur; p++) {
            cur = child[cur][id(p)];
        }
        printf("cur %d\n", cur);
        return child[cur][0] || child[cur][1];
    }

};

char code[10][15];

int main(void){
    int num = 0;
    int kase = 0;
    while(scanf("%s", code[num]) != EOF) {
        if(code[num][0] != '9') num++;
        else {
            Trie t;
            bool flag = true;
            for(int i = 0; i < num; i++) t.insert(code[i], 1);
            printf("Set %d is ", ++kase);
            for(int i = 0; i < num; i++)
                if(t.query(code[i])) {
                    printf("not immediately decodable\n");
                    flag = false;
                    break;
                }
            if(flag) printf("immediately decodable\n");
            num = 0;
        }
    }
    return 0;
}
