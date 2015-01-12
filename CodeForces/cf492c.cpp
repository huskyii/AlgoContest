#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;
const int MAXN = 100000 + 10;
struct Exam {
    int64 a, b;
    bool operator<(const Exam &e) const {
        return b < e.b;
    }
};
Exam e[MAXN];

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int64 n, r, avg;
    while(cin >> n >> r >> avg) {
        int64 required = avg * n, tot = 0;
        for(int i = 0; i < n; ++i) {
            cin >> e[i].a >> e[i].b;
            tot += e[i].a;
        }
        int64 rest = required - tot;
        if(rest <= 0) {
            cout << 0 << endl;
            continue;
        }
        sort(e, e+n);
        int64 ans = 0;
        for(int i = 0; i < n; ++i) {
            int avaiable = r - e[i].a;
            if(avaiable >= rest) {
                ans += e[i].b * rest;
                break;
            } else {
                ans += e[i].b * avaiable;
                rest -= avaiable;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
