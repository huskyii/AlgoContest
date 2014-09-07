// TODO WA
/****************************************/
/*          author: jiang.zhu           */
/*    email: mail.jiang.cn@gmail.com    */
/*      created on 2014-09-05           */
/****************************************/
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

struct DisjointSet {
    vector<int> father, rank;

    DisjointSet(int n): father(n), rank(n) {
        for(int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    int find(int v) {
        int fv = father[v];
        while(fv != v) {
            v = fv;
            fv = father[v];
        }
        return v;
    }

    void merge(int x, int y) {
        int a = find(x), b = find(y);
        if(rank[a] < rank[b]) {
            father[a] = b;
        } else {
            father[b] = a;
            if(rank[a] == rank[b])
                ++rank[a];
        }
    }
};

int v[2010];

int main(void){
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++) {
        memset(v, 0, sizeof(v));
        int n, m;
        scanf("%d %d", &n, &m);

        DisjointSet d = DisjointSet(n + 1);
        bool flag = true;

        int i, j, pi = 0, pj = 0;
        while(m--) {
            scanf("%d %d", &i, &j);
            if(!flag) continue;
            v[i] = d.find(i);
            v[j] = d.find(j);

            if(d.find(i) == d.find(j))
                flag = false;

            if(d.find(pj) == v[i] || d.find(pi) == v[j]) {
                d.merge(i, pj);
                d.merge(j, pi);
            } else {
                d.merge(i, pi);
                d.merge(j, pj);
            }

            pi = i;
            pj = j;
        }

        printf("Scenario #%d:\n", kase);
        if(flag) printf("No suspicious bugs found!\n\n");
        else printf("Suspicious bugs found!\n\n");
    }
    return 0;
}
