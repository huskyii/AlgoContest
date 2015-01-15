#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int N, S, Q;
    cin >> N;
    for(int kase = 1; kase <= N; ++kase) {
        string se;
        cin >> S;
        getline(cin, se);
        for(int i = 0; i < S; ++i) {
            getline(cin, se);
        }
        cin >> Q;
        getline(cin, se);
        int cnt = 0;
        set<string> ses;
        for(int i = 0; i < Q; ++i) {
            getline(cin, se);
            if(ses.find(se) == ses.end() &&
                    ses.size() == (size_t)S-1) {
                cnt++;
                ses.clear();
            }
            ses.insert(se);
        }
        printf("Case #%d: %d\n", kase, cnt);
    }
    return 0;
}
