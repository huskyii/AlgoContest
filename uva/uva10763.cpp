//#define debug
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

#define MAXN 500005

int orgin[MAXN];
int dest[MAXN];

int main(void){
#ifdef debug
    freopen("uva10763.in", "r", stdin);
#endif
    int n;
    while(scanf("%d", &n) == 1 && n){
        for(int i = 0; i < n; i++){
            scanf("%d %d", orgin+i, dest+i);
        }
        sort(orgin, orgin+n);
        sort(dest, dest+n);
        if(memcmp(orgin, dest, sizeof(int)*n) == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    /*
     *int key, val;
     *map<int, int> exchange;
     *pair< map<int, int>::iterator, map<int, int>::iterator > range;
     *while(scanf("%d", &n) == 1 && n){
     *    while(n--){
     *        int flag = 0;
     *        scanf("%d %d", &key, &val);
     *        range = exchange.equal_range(val);
     *        if(range.first->first == val){
     *            for(map<int, int>::iterator it = range.first; it != range.second; it++)
     *                if(it->second == key){
     *                    exchange.erase(it);
     *                    flag = 1;
     *                    break;
     *                }
     *        }
     *        if(flag)
     *            continue;
     *        exchange.insert(make_pair(key, val));
     *    }
     *    if(exchange.empty())
     *        printf("YES\n");
     *    else
     *        printf("NO\n");
     *    exchange.clear();
     *}
     */
    return 0;
}
