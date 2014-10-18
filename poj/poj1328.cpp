#include <cstdio>
#include <algorithm>
#include <cmath>

struct coordinate {
    int x, y;
    double s, e;
    bool operator<(const coordinate &o) const {
        return e < o.e;
    }
} island[1001];

int solve(int n, int d) {
    for (int i = 0; i < n; ++i) {
        double t = sqrt(d - island[i].y * island[i].y);
        island[i].s = island[i].x - t;
        island[i].e = island[i].x + t;
    }

    std::sort(island, island + n);

    int ans = 1;
    double r = island[0].e;
    for (int i = 1; i < n; ++i) {
        if (island[i].s > r) {
            ++ans;
            r = island[i].e;
        }
    }
    return ans;
}

int main(void) {
    int kase = 0;
    int n, d;
    while (scanf("%d %d", &n, &d) && (n || d)) {
        bool np = false;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &island[i].x, &island[i].y);
            if (island[i].y > d) {
                np = true;
            }
        }
        if (np) {
            printf("Case %d: %d\n", ++kase, -1);
        } else {
            printf("Case %d: %d\n", ++kase, solve(n, d * d));
        }
    }

    return 0;
}

