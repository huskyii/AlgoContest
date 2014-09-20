/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-08-31			*/
/****************************************/
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 20005;
int a[maxn], c[maxn], d[maxn], n;

struct BIT {
    int size;
    vector<int> bit;

    void clear() {
        fill(bit.begin(), bit.end(), 0);
    }

    void resize(int size) {
        this->size = size;
        bit.resize(size);
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
            i = i&(i-1);
        }
        return s;
    }
};

int main(void){
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        int maxa = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", a+i);
            maxa = maxa > a[i] ? maxa: a[i];
        }

        BIT t;
        t.resize(maxa);
        t.clear();
        for(int i = 1; i <= n; i++) {
            t.add(a[i], 1);
            c[i] = t.sum(a[i] - 1);
        }
        t.clear();
        for(int i = n; i > 0; i--) {
            t.add(a[i], 1);
            d[i] = t.sum(a[i] - 1);
        }

        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += (long long)c[i]*(n-i-d[i]) + (long long)(i-c[i]-1)*d[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
