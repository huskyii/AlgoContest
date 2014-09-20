/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-08-22			*/
/****************************************/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct T{
    vector<int> input;
    vector<int> output;
    void clear(){
        input.clear();
        output.clear();
    }
};

T t[105];
int p[105];

inline bool check(const T &tr){
    for(vector<int>::const_iterator it = tr.input.begin();
            it != tr.input.end(); it++){
        if(p[*it] - count(tr.input.begin(), tr.input.end(), *it) < 0){
            return false;
        }
    }
    return true;
}

inline void update(T &tr){
    for(vector<int>::iterator it = tr.input.begin();
            it != tr.input.end(); it++){
        p[*it]--;
    }
    for(vector<int>::iterator it = tr.output.begin();
            it != tr.output.end(); it++){
        p[*it]++;
    }
}

inline bool simulate(int nt){
    for(int i = 1; i <= nt; i++){
        if(check(t[i])){
            update(t[i]);
            return true;
        }
    }
    return false;
}

int main(void){
    int kase = 0;
    int np, nt, nf;
    while(scanf("%d", &np) == 1 && np){
        bool flag = true;
        int tmp;
        printf("Case %d: ", ++kase);
        for(int i = 1; i <= np; i++){
            scanf("%d ", p+i);
        }
        scanf("%d", &nt);
        for(int i = 1; i <= nt; i++){
            t[i].clear();
        }
        for(int i = 1; i <= nt; i++){
            while(scanf("%d ", &tmp) == 1 && tmp){
                tmp > 0? t[i].output.push_back(tmp):t[i].input.push_back(-tmp);
            }
        }
        scanf("%d", &nf);
        for(int i = 0; i < nf; i++){
            if(!simulate(nt)){
                printf("dead after %d transitions\n", i);
                flag = false;
                break;
            }
        }
        if(flag){
            printf("still live after %d transitions\n", nf);
        }
        printf("Places with tokens:");
        for(int i = 1; i <= np; i++){
            if(p[i] > 0){
                printf(" %d (%d)", i, p[i]);
            }
        }
        printf("\n\n");
    }
    return 0;
}
