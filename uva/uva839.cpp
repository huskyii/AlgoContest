//#define debug
#include <cstdio>
#include <iostream>
using namespace std;

int solve(){
    bool flag = true;
    int wl, dl, wr, dr;
    scanf("%d %d %d %d", &wl, &dl, &wr, &dr);
    //cout << wl << " " << dl << " " << wr << " " << dr << endl;
    if(wl == 0){
        if((wl = solve()) == 0){
            flag = false;
        }
    }
    if(wr == 0){
        if((wr = solve()) == 0){
            flag = false;
        }
    }
    if((wl * dl == wr * dr) && flag){
        return (wl+wr);
    }else{
        return 0;
    }
}

int main(void){
#ifdef debug
    freopen("uva839.in", "r", stdin);
#endif
    int kase;
    scanf("%d", &kase);
    getchar();
    while(kase--){
        solve() ? printf("YES\n") : printf("NO\n");
        if(kase)
            printf("\n");
        getchar();
    }
    return 0;
}

/*
 *bool solve(int &W){
 *    int W1, W2, D1, D2;
 *    bool b1 = true, b2 = true;
 *    cin >> W1 >> D1 >> W2 >> D2;
 *    if(!W1) b1 = solve(W1);
 *    if(!W2) b2 = solve(W2);
 *    W = W1 + W2;
 *    return b1 && b2 && (W1*D1 == W2*D2);
 *}
 *
 *int main(void){
 *#ifdef debug
 *    freopen("uva839.in", "r", stdin);
 *#endif
 *    int T, W;
 *    cin >> T;
 *    while(T--){
 *        if(solve(W))
 *            cout << "YES\n";
 *        else
 *            cout << "NO\n";
 *        if(T)
 *            cout << endl;
 *    }
 *    return 0;
 *}
 */
