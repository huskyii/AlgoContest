#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXN 100000

int sum[MAXN];

void build(int p){
    int v;
    cin >> v;
    if(v == -1)
        return ;
    sum[p] += v;
    build(p-1);
    build(p+1);
}

bool init(){
    int v;
    cin >> v;
    if(v == -1)
        return false;
    memset(sum, 0, sizeof(sum));
    sum[MAXN/2] = v;
    build(MAXN/2 - 1);
    build(MAXN/2 + 1);
    return true;
}

int main(void){
    int kase = 0;
    while(init()){
        int p = MAXN/2;
        while(sum[p] != 0){
            p--;
        }
        p++;
        cout << "Case " << ++kase << ":" << endl << sum[p++];
        while(sum[p] != 0)
            cout << " " << sum[p++];
        cout << endl << endl;
    }
    return 0;
}
