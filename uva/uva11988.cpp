#define debug
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

#define MAXN 100005
char text[MAXN];
int next_char[MAXN];
size_t len;
int last, cur;

int main(void){
#ifdef debug
    freopen("uva11988.in", "r", stdin);
#endif
    while(scanf("%s", text+1) != EOF){
        last = 0;
        cur = 0;
        len = strlen(text+1);
        next_char[0] = 0;
        for(size_t i = 1; i <= len; i++){
            if(text[i] == '[')
                cur = 0;
            else if(text[i] == ']')
                cur = last;
            else{
                next_char[i] = next_char[cur];
                next_char[cur] = i;
                if(cur == last)
                    last = i;
                cur = i;
            }
        }
        for(int i = next_char[0]; i != 0; i = next_char[i]){
            //cout << i << " ";
            putchar(text[i]);
        }
        putchar('\n');
    }
    return 0;
}
