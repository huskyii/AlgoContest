// #define LOCAL
#include <cstdio>
#include <cstring>

int grid[201][201];

bool col[201][201];
bool row[201];
int ans[201];

int main(void){
#ifdef LOCAL
    freopen("hdu3225.in", "r", stdin);
    freopen("hdu3225.out", "w", stdout);
#endif
    int T, M, flag, N, K, kase = 0;
    scanf("%d", &T);
    while(T--){
        memset(col, 0, sizeof(col));
        scanf("%d %d %d", &N, &M, &K);
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < N; ++j){
                scanf("%d", &grid[i][j]);
                col[j][grid[i][j]] = 1;
            }
        if(K > N-M)
            printf("Case #%d: -1\n", ++kase);
        else{
            flag = 0;
            memset(ans, 0, sizeof(ans));
            printf("Case #%d:", ++kase);
            for(int k = 0; k < K; ++k){
                memset(row, 0, sizeof(row));
                for(int i = 0; i < N; ++i)
                    for(int j = 1; j <= N; ++j)
                        if(col[i][j] == 0 && row[j]==0){
                            col[i][j] = 1;
                            row[j] = 1;
                            if(k == K-1)
                                ans[i] = j;
                            break;
                        }
            }
            for(int i = 0; i < N; ++i)
                if(ans[i] == 0){
                    flag = 1;
                    break;
                }
            if(flag)
                printf(" -1");
            else
                for(int i = 0; i < N; ++i)
                    printf(" %d", ans[i]);
            printf("\n");
        }
    }
    return 0;
}
