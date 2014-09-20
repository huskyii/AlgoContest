#define debug
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

int main(void){
#ifdef debug
    freopen("uva210.in", "r", stdin);
#endif
    int kase;
    scanf("%d", &kase);
    while(kase--){
        int exec_time[5];
        deque< pair<int, vector<string> > > programs;
        int quantum, n;
        string str;
        getchar();
        scanf("%d %d %d %d %d %d %d", &n, exec_time, exec_time+1, exec_time+2, exec_time+3, exec_time+4, &quantum );
        for(int i = 1; i <= n; ){
            vector<string> program;
            for(; ; ){
                string statement;
                cin >> statement;
                program.push_back(statement);
                if(statement == "end"){
                    programs.push_back(make_pair(i, program));
                    i++;
                    break;
                }
            }
        }
    }
    return 0;
}
