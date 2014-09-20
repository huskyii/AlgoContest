#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include "vector"
using namespace std;

int main(void){
    //set< vector<int> > duccis;
    int T, n, flag, tmp;
    scanf("%d", &T);
    while(T--){
        vector<int> ducci;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &tmp);
            ducci.push_back(tmp);
        }
        vector<int> new_ducci(ducci);
        for(int j = 0; j < 1000; j++){
            flag = 0;
            for(int i = 0; i < n; i++){
                new_ducci[i] = abs(ducci[i]-ducci[(i+1)%n]);
            }
            for(int i = 0; i < n; i++)
                if(new_ducci[i] != 0){
                    flag = 2;
                    break;
                }
            /*
             *for(int i = 0; i < n; i++){
             *    printf("%d ", ducci[i]);
             *}
             *printf("\n");
             *for(int i = 0; i < n; i++){
             *    printf("%d ", new_ducci[i]);
             *}
             *printf("\n");
             */
            /*
             *if(duccis.find(new_ducci) != duccis.end()){
             *    flag = 1;
             *}
             */
            //duccis.insert(new_ducci);
            ducci = new_ducci;
        }
        if(flag == 0){
            printf("ZERO\n");
        }else{
            printf("LOOP\n");
        }
    }
    return 0;
}
