/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-08-31			*/
/****************************************/
#include <cstdio>
#include <vector>
using namespace std;

typedef long long int64;

struct BIT {
    int size;
    vector<int64> bit;

    void resize(int size) {
        bit.resize(size+1);
        this->size = size;
    }

    void clear() {
        fill(bit.begin(), bit.end(), 0);
    }

    void add(int i, int x) {
        while(i <= size) {
            bit[i] += x;
            i += i&-i;
        }
    }

    int64 sum(int i) {
        int64 s = 0;
        while(i > 0) {
            s += bit[i];
            i -= i&-i;
        }
        return s;
    }
};

const int maxn = 200005;
int arr[maxn];
BIT t;

int main(void){
    int kase = 0;
    int n;
    while(scanf("%d", &n) == 1 && n) {
        if(kase){
            printf("\n");
        }
        printf("Case %d:\n", ++kase);

        t.resize(n);
        t.clear();

        for(int i = 1; i <= n; i++) {
            scanf("%d", arr+i);
            t.add(i, arr[i]);
        }

        char action[20];
        int a, b;
        while(scanf("%s", action) && action[0] != 'E') {
            scanf("%d", &a);
            scanf("%d", &b);
            scanf("%d %d", &a, &b);
            if(action[0] == 'S') {
                //printf("set %d = %d\n", a, b);
                t.add(a, b - arr[a]);
                arr[a] = b;
            } else if(action[0] == 'M') {
                //printf("measure %d =-> %d  ", a, b);
                int64 sum = t.sum(b) - t.sum(a-1);
                printf("%lld\n", sum);
            }
        }
    }
    return 0;
}
