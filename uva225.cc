// TODO
/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-09-03			*/
/****************************************/
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;

map<int, set<int> > xx;
map<int, set<int> > yy;
set< pair<int, int> > v;
char route[22];
int maxd, cnt;

void dfs(char dir, int step, int x, int y) {
    int offset = abs(x) + abs(y);
    if(offset > (maxd+step)*(maxd-step+1)/2) return ;
    if(dir == 'n') {
        if(xx[x].lower_bound(y+step) == xx[x].upper_bound(y) &&
                v.find(make_pair(x, y+step)) == v.end()) {
            route[step] = dir;
            if(step == maxd) {
                if(x == 0 && y+step == 0) {
                    cnt++;
                    for(int i = 0; i <= step; i++)
                        printf("%c", route[i]);
                    printf("\n");
                }
                return ;
            }
            v.insert(make_pair(x, y+step));
            dfs('w', step+1, x, y+step);
            dfs('e', step+1, x, y+step);
            v.erase(make_pair(x, y+step));
        }
    } else if(dir == 's') {
        if(xx[x].lower_bound(y) == xx[x].upper_bound(y-step) &&
                v.find(make_pair(x, y-step)) == v.end()) {
            route[step] = dir;
            if(step == maxd) {
                if(x == 0 && y-step == 0) {
                    cnt++;
                    for(int i = 0; i <= step; i++)
                        printf("%c", route[i]);
                    printf("\n");
                }
                return ;
            }
            v.insert(make_pair(x, y-step));
            dfs('w', step+1, x, y-step);
            dfs('e', step+1, x, y-step);
            v.erase(make_pair(x, y-step));
        }
    } else if(dir == 'w') {
        if(yy[y].lower_bound(x) == yy[y].upper_bound(x-step) &&
                v.find(make_pair(x-step, y)) == v.end()) {
            route[step] = dir;
            if(step == maxd) {
                if(x-step == 0 && y == 0) {
                    cnt++;
                    for(int i = 0; i <= step; i++)
                        printf("%c", route[i]);
                    printf("\n");
                }
                return ;
            }
            v.insert(make_pair(x-step, y));
            dfs('n', step+1, x-step, y);
            dfs('s', step+1, x-step, y);
            v.erase(make_pair(x-step, y));
        }
    } else if(dir == 'e') {
        if(yy[y].lower_bound(x+step) == yy[y].upper_bound(x) &&
                v.find(make_pair(x+step, y)) == v.end()) {
            route[step] = dir;
            if(step == maxd) {
                if(x+step == 0 && y == 0) {
                    cnt++;
                    for(int i = 0; i <= step; i++)
                        printf("%c", route[i]);
                    printf("\n");
                }
                return ;
            }
            v.insert(make_pair(x+step, y));
            dfs('n', step+1, x+step, y);
            dfs('s', step+1, x+step, y);
            v.erase(make_pair(x+step, y));
        }
    }
    return ;
}

int main(void){
    int T;
    scanf("%d", &T);
    while(T--) {
        xx.clear(), yy.clear();
        int n, x, y;
        scanf("%d", &maxd);
        scanf("%d", &n);
        while(n--) {
            scanf("%d %d", &x, &y);
            xx[x].insert(y);
            yy[y].insert(x);
        }

        cnt = 0;
        v.clear();
        dfs('n', 1, 0, 0);
        dfs('s', 1, 0, 0);
        dfs('w', 1, 0, 0);
        dfs('e', 1, 0, 0);
        printf("Found %d golygon(s).\n\n", cnt);
    }
    return 0;
}
