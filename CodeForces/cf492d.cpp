#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;
const string str[4] = { "", "Vanya", "Vova", "Both" };

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, x, y, a;
    while(cin >> n >> x >> y) {
        int64 cntx = 0, cnty = 0;
        // 1 : Vanya, 2 : Vova, 3 : Both
        vector<int> res;
        while(cntx < x || cnty < y) {
            if((cntx+1)*y > (cnty+1)*x) {
                res.push_back(2);
                cnty++;
            } else if((cntx+1)*y < (cnty+1)*x) {
                res.push_back(1);
                cntx++;
            } else {
                res.push_back(3);
                res.push_back(3);
                cntx++;
                cnty++;
            }
        }
        for(int i = 0; i < n; ++i) {
            cin >> a;
            cout << str[res[(a-1)%(x+y)]] << endl;
        }
    }
    return 0;
}
