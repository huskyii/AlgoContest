//#define debug
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 10000

void solve(int n){
    int target[MAXN];
    while(scanf("%d", target+1) == 1 && *(target+1)){
        bool ok = true;
        int a = 1, b = 1;
        stack<int> station;
        for(int i = 2; i <= n; i++)
            scanf("%d", target+i);
        while(b <= n){
            if(a == target[b]){
                a++; b++;
            }else if(!station.empty() && station.top() == target[b]){
                station.pop();
                b++;
            }else if(a <= n){
                station.push(a++);
            }else{
                ok = false;
                break;
            }
        }
        printf("%s\n", ok? "Yes": "No");
    }
}

int main(void){
#ifdef debug
    freopen("uva514.in", "r", stdin);
#endif
    int n;
    while(true){
        if(scanf("%d", &n) == 1 && n){
            solve(n);
            printf("\n");
        }
        else
            break;
    }
    return 0;
}
