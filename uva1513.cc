/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-09-01			*/
/****************************************/
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100005;
int p[maxn];

struct BIT {
    int size;
    vector<int> bit;

    void clear() {
        fill(bit.begin(), bit.end(), 0);
    }

    void resize(int size) {
        this->size = size;
        bit.resize(size+1);
    }

    void add(int i, int x) {
        while(i <= size) {
            bit[i] += x;
            i += i&-i;
        }
    }

    int sum(int i) {
        int s = 0;
        while(i > 0) {
            s += bit[i];
            i -= i&-i;
        }
        return s;
    }

};

int main(void){
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d %d", &n, &m);

        BIT t;
        t.resize(n+m);
        t.clear();

        for(int i = 1; i <= n; i++) {
            t.add(i, 1);
            p[i] = n - i + 1;
        }

        int x;
        for(int i = 1; i <= m; i++) {
            scanf("%d", &x);
            if(i > 1) printf(" ");
            printf("%d", n - t.sum(p[x]));
            t.add(p[x], -1);
            p[x] = n + i;
            t.add(p[x], 1);
        }
        printf("\n");
    }
    return 0;
}
