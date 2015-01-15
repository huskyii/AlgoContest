#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct Time {
    int h, m;
    void add(int minute) {
        h += (minute + m) / 60;
        m = (minute + m) % 60;
    }
    bool operator<(const Time &t) const {
        if(h < t.h) return true;
        else if(h > t.h) return false;
        else return m < t.m;
    }
    bool operator<=(const Time &t) const {
        return (*this) < t || (t.h == h && t.m == m);
    }
};

Time aa[100], ad[100], ba[100], bd[100];

int main(void) {
    int N, T, NA, NB;
    cin >> N;
    for(int kase = 1; kase <= N; ++kase) {
        cin >> T;
        cin >> NA >> NB;
        for(int i = 0; i < NA; ++i) {
            scanf("%d:%d", &ad[i].h, &ad[i].m);
            scanf("%d:%d", &aa[i].h, &aa[i].m);
            aa[i].add(T);
        }
        for(int i = 0; i < NB; ++i) {
            scanf("%d:%d", &bd[i].h, &bd[i].m);
            scanf("%d:%d", &ba[i].h, &ba[i].m);
            ba[i].add(T);
        }
        sort(aa, aa+NA);
        sort(ad, ad+NA);
        sort(ba, ba+NB);
        sort(bd, bd+NB);
        int cnta = 0;
        for(int i = 0, j = 0; i < NB; ++i) {
            while(j < NA) {
                if(ba[i] <= ad[j]) {cnta++; ++j; break;}
                j++;
            }
            if(j >= NA) break;
        }
        cnta = NA - cnta;
        int cntb = 0;
        for(int i = 0, j = 0; i < NA; ++i) {
            while(j < NB) {
                if(aa[i] <= bd[j]) {cntb++; ++j; break;}
                j++;
            }
            if(j >= NB) break;
        }
        cntb = NB - cntb;
        printf("Case #%d: %d %d\n", kase, cnta, cntb);
    }
    return 0;
}
