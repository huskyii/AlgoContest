/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-08-24			*/
/****************************************/
#include <cstdio>
#include <vector>
using namespace std;

int main(void){
    int k;
    vector<int> X, Y;
    while(scanf("%d ", &k) != EOF){
        X.clear();
        Y.clear();
        for(int y = k+1; y <= 2*k; y++){
            if((k*y)%(y-k) == 0){
                X.push_back((k*y)/(y-k));
                Y.push_back(y);
            }
        }
        printf("%d\n", (int)X.size());
        for(size_t i = 0; i < X.size(); i++){
            printf("1/%d = 1/%d + 1/%d\n", k, X[i], Y[i]);
        }
    }
    return 0;
}
