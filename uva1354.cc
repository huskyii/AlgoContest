/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-08-27			*/
/****************************************/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct Tree {
    double L,R;
    Tree():L(0), R(0) {}
};

const int MAXS = 6;
bool v[1<<MAXS];
double r, w[MAXS], sum[1<<MAXS];
int s;
vector<Tree> tree[1<<MAXS];

void dfs(int subset) {
    if(v[subset])
        return ;
    v[subset] = true;

    bool have_children = false;
    for(int left = (subset-1)&subset; left; left = (left-1)&subset) {
        have_children = true;

        int right = subset^left;
        double d1 = sum[right]/sum[subset];
        double d2 = sum[left]/sum[subset];

        dfs(left);
        dfs(right);

        for(size_t i = 0; i < tree[left].size(); i++) {
            for(size_t j = 0; j < tree[right].size(); j++) {
                Tree t;
                t.R = max(tree[right][j].R + d2, tree[left][i].R - d1);
                t.L = max(tree[left][i].L + d1, tree[right][j].L - d2);
                if(t.R + t.L < r) {
                    tree[subset].push_back(t);
                }
            }
        }
    }

    if(!have_children) {
        tree[subset].push_back(Tree());
    }
}

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%lf", &r);
        memset(v, 0, sizeof(v));
        memset(sum, 0, sizeof(sum));
        scanf("%d", &s);
        for(int i = 0; i < s; i++) {
            scanf("%lf", w+i);
        }
        for(int i = 0; i < (1<<s); i++) {
            tree[i].clear();
            for(int j = 0; j < s; j++)
                if(i&(1<<j))
                    sum[i] += w[j];
        }

        int root = (1 << s) - 1;
        dfs(root);

        double ans = -1;
        for(size_t i = 0; i < tree[root].size(); i++) {
            ans = max(ans, tree[root][i].L + tree[root][i].R);
        }
        printf("%.10lf\n", ans);
    }
    return 0;
}
