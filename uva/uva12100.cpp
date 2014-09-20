//#define debug
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int main(void){
#ifdef debug
    freopen("uva12100.in", "r", stdin);
    freopen("uva12100.out", "w", stdout);
#endif
    int T, n, m, tmp;
    int count[10];
    bool flag;
    pair<int, int> current;
    scanf("%d", &T);
    while(T--){
        memset(count, 0, sizeof(count));
        int time = 0;
        queue< pair<int, int> > print;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++){
            scanf("%d", &tmp);
            print.push(make_pair(tmp, i));
            count[tmp]++;
        }
        /*
         *for(int i = 0; i < 10; i++)
         *    cout << count[i];
         *cout << endl;
         */
        for(; ; ){
            flag = true;
            current = print.front();
            print.pop();
            //cout << time << " " << current.first << " " << current.second;
            for(int i = 9; i > current.first; i--){
                if(count[i] != 0){
                    print.push(current);
                    flag = false;
                    break;
                }
            }
            if(flag){
                if(current.second == m)
                    break;
                else{
                    count[current.first]--;
                    time++;
                }
            }
        }
        printf("%d\n", time+1);
    }
    return 0;
}
